// ConsumerProductorModel.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

using namespace std;

CRITICAL_SECTION g_csRepo;

int iCountProduct;
int iCountConsume;

HANDLE g_ProductSemaphore;
HANDLE g_consumeSemaphore;

HANDLE g_RepoEmpty;
HANDLE g_RepoFull;

const int REPO_SIZE     = 10;
const int PRODUCT_TOTAL = 100;

struct Repo
{
    int iBuffer[REPO_SIZE];
    int iProductPosition;
    int iConsumePosition;
    BOOL bIsEmpty;
    BOOL bIsFull;
}g_repo;

//struct Repo *g_repo;

void InitRepo()
{
    iCountProduct = 0;
    iCountConsume = 0;
    g_repo.bIsEmpty = TRUE;
    g_repo.bIsFull  = FALSE;
    g_repo.iConsumePosition = 0;
    g_repo.iProductPosition = 0;
}

DWORD WINAPI ProductTask(LPVOID param)
{        
    while(TRUE)
    {
        Sleep(50);
        EnterCriticalSection(&g_csRepo);
        //任务是否完成
        if (PRODUCT_TOTAL == iCountProduct)
        {
            cout<<"生产任务完成"<<endl;
            LeaveCriticalSection(&g_csRepo);
            ReleaseSemaphore(g_ProductSemaphore,1,NULL);
            return NULL;
        }
        //仓库是否满了
        if (g_repo.bIsFull)
        {
            cout<<"仓库满了"<<endl;
            LeaveCriticalSection(&g_csRepo);
            continue;
        }
        else
        {
            int iTemp = (int)10*rand()/RAND_MAX;
            g_repo.iBuffer[g_repo.iProductPosition] = iTemp;
            iCountProduct ++;
            cout << "Product No." << iCountProduct <<"=" << iTemp <<" ProductPositon ="<< g_repo.iProductPosition <<"ConsumePosition = " << g_repo.iConsumePosition <<endl;
            
            g_repo.iProductPosition++;
            if (g_repo.iProductPosition == REPO_SIZE)
            {
                g_repo.iProductPosition = 0;
            }
            if (g_repo.iProductPosition == g_repo.iConsumePosition)
            {
                cout<<"仓库满了，修改标志位"<<endl;
                g_repo.bIsFull = TRUE;
            }
            g_repo.bIsEmpty = FALSE;
        }
        
        LeaveCriticalSection(&g_csRepo);
    }
    
    return NULL;
}

DWORD WINAPI ConsumeTask(LPVOID param)
{   
    while(TRUE)
    {   
        Sleep(50); 
        EnterCriticalSection(&g_csRepo);
               
        if (PRODUCT_TOTAL == iCountConsume)
        {
            LeaveCriticalSection(&g_csRepo);
            cout<<"消费任务完成"<<endl;
            ReleaseSemaphore(g_consumeSemaphore,1,NULL);
            return NULL;
        }
        if (g_repo.bIsEmpty)
        {            
            cout << "仓库空了"<<endl;
            LeaveCriticalSection(&g_csRepo);
            continue;
        }

        else
        {
            int iTemp = 0;
            iTemp = g_repo.iBuffer[g_repo.iConsumePosition] ;
            iCountConsume ++;         
            cout << "Consume No." << iCountConsume << "=" << iTemp <<" ProductPositon ="<< g_repo.iProductPosition <<"ConsumePosition = " << g_repo.iConsumePosition << endl;           
            
            g_repo.bIsFull = FALSE;
            g_repo.iConsumePosition++;
            if(g_repo.iConsumePosition == REPO_SIZE )
            {
                g_repo.iConsumePosition = 0;
            }
            if (g_repo.iConsumePosition == g_repo.iProductPosition)
            {
                cout <<"仓库空了，置标志位" <<endl;
                g_repo.bIsEmpty = TRUE;
            }            
        }
        LeaveCriticalSection(&g_csRepo);
    }

    return NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
    InitializeCriticalSection(&g_csRepo);
    InitRepo();
    g_ProductSemaphore = CreateSemaphore(NULL,0,1,NULL);
    g_consumeSemaphore = CreateSemaphore(NULL,0,1,NULL);

    HANDLE ThreadProduct = CreateThread( NULL, 0, ProductTask, NULL, NULL, NULL);
    HANDLE ThreadConsume = CreateThread( NULL, 0, ConsumeTask, NULL, NULL, NULL);

    CloseHandle(ThreadConsume);
    CloseHandle(ThreadProduct);
    
    WaitForSingleObject(g_ProductSemaphore,INFINITE);
    WaitForSingleObject(g_consumeSemaphore,INFINITE);

    CloseHandle(g_ProductSemaphore);
    CloseHandle(g_consumeSemaphore);

    DeleteCriticalSection(&g_csRepo);

    system("pause");
	return 0;
}

