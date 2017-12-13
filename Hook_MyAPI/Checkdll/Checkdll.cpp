// Checkdll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Checkdll.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{  
    Checkdll cd;
    cd.AddReal(2,3);

    system("pause");
	return 0;
}

Checkdll::Checkdll()
{

}

Checkdll::~Checkdll()
{

}

void Checkdll::AddReal(int a,int b)
{
    HMODULE hDll = NULL;
    hDll = LoadLibrary(L"MyAddTest.dll.dll");
    if (hDll == NULL)
    {
        cout<< "load dll error" <<endl;
        return ;
    }

    add=(AddProc)::GetProcAddress(hDll,"add");
    if (add == NULL)
    {
        cout<< "func add NULL" <<endl;
        return ;
    }
    int iRet = add(a,b);
    cout << iRet <<endl;
}
