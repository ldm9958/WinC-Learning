// Hook_MyAPI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <afxwin.h >
#include "Hook_MyAPI.h"

#pragma data_seg("SHARED")
static HHOOK  hhk=NULL; //鼠标钩子句柄
static HINSTANCE hinst=NULL; //本dll的实例句柄 (hook.dll)
#pragma data_seg()
#pragma comment(linker, "/section:SHARED,rws")

bool bHook=false; //是否Hook了函数
bool m_bInjected=false; //是否对API进行了Hook
BYTE OldCode[5]; //老的系统API入口代码
BYTE NewCode[5]; //要跳转的API代码 (jmp xxxx)
typedef int (WINAPI*AddProc)(int a,int b);//add.dll中的add函数定义
AddProc add; //add.dll中的add函数
HANDLE hProcess=NULL; //所处进程的句柄
FARPROC pfadd;  //指向add函数的远指针
DWORD dwPid;  //所处进程ID
//end of 变量定义

//函数定义
void HookOn(); //开启钩子
void HookOff(); //关闭钩子
LRESULT CALLBACK MouseProc(int nCode,WPARAM wParam,LPARAM lParam); //鼠标钩子函数
void Inject(); //具体进行注射，替换入口的函数
int WINAPI Myadd(int a,int b); //我们定义的新的add()函数
BOOL InstallHook(); //安装钩子函数
void UninstallHook(); //卸载钩子函数
//end of 函数定义


BOOL HOOK_MyAPI::InitInstance() 
{
    //获取自身dll句柄
    hinst=::AfxGetInstanceHandle();
    //获取所属进程id和句柄
    DWORD dwPid=::GetCurrentProcessId();
    hProcess=OpenProcess(PROCESS_ALL_ACCESS,0,dwPid); 
    //调用函数注射
    Inject();

    return TRUE;
}

BOOL InstallHook()
{

    hhk=::SetWindowsHookEx(WH_MOUSE,MouseProc,hinst,0);

    if (hhk==NULL)
    {
        return false;
    }

    return true;
}

void UninstallHook()
{
    if (hhk!=NULL)
        ::UnhookWindowsHookEx(hhk);
}

void Inject()
{

    if (m_bInjected==false)
    {
        m_bInjected=true;


        //读取add.dll并查找到add()函数
        HMODULE hmod=::LoadLibrary(L"MyAddTest.dll.dll");
        add=(AddProc)::GetProcAddress(hmod,"add");
        pfadd=(FARPROC)add;

        if (pfadd==NULL)
        {
            return ;
        }

        // 将add()的入口代码保存到OldCode里
        _asm 
        { 
            lea edi,OldCode 
                mov esi,pfadd 
                cld 
                movsd 
                movsb 
        }

        NewCode[0]=0xe9;//第一个字节0xe9相当于jmp指令
        //获取Myadd()的相对地址
        _asm 
        { 
            lea eax,Myadd
                mov ebx,pfadd 
                sub eax,ebx 
                sub eax,5 
                mov dword ptr [NewCode+1],eax 
        } 
        //填充完毕，现在NewCode[]里面就相当于指令 jmp Myadd
        HookOn();
    }
}

int WINAPI Myadd(int a,int b)
{
    //截获了对add()的调用，我们给a,b都加1
    a=a+1;
    b=b+1;


    HookOff();//关掉Myadd()钩子防止死循环

    int ret;
    ret=add(a,b);

    HookOn();//开启Myadd()钩子

    return ret;
}

LRESULT CALLBACK MouseProc(
                           int nCode,      // hook code
                           WPARAM wParam,  // message identifier
                           LPARAM lParam   // mouse coordinates
                           )
{

    LRESULT RetVal= CallNextHookEx(hhk,nCode,wParam,lParam);
    return RetVal;
}


void HookOn() 
{ 
    assert(hProcess!=NULL);

    DWORD dwTemp=0;
    DWORD dwOldProtect;

    //将内存保护模式改为可写,老模式保存入dwOldProtect
    VirtualProtectEx(hProcess,pfadd,5,PAGE_READWRITE,&dwOldProtect); 
    //将所属进程中add的前5个字节改为Jmp Myadd 
    WriteProcessMemory(hProcess,pfadd,NewCode,5,0);
    //将内存保护模式改回为dwOldProtect
    VirtualProtectEx(hProcess,pfadd,5,dwOldProtect,&dwTemp);

    bHook=true; 
}

void HookOff()//将所属进程中add()的入口代码恢复
{ 
    assert(hProcess!=NULL);

    DWORD dwTemp=0;
    DWORD dwOldProtect;

    VirtualProtectEx(hProcess,pfadd,5,PAGE_READWRITE,&dwOldProtect); 
    WriteProcessMemory(hProcess,pfadd,OldCode,5,0); 
    VirtualProtectEx(hProcess,pfadd,5,dwOldProtect,&dwTemp); 
    bHook=false; 
}

HOOK_MyAPI::HOOK_MyAPI()
{

}

HOOK_MyAPI::~HOOK_MyAPI()
{

}
