// MultiProductorConsumerModel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <queue>

const int ITEM_QUATITY  = 100;  //产品计划总量
const int REPO_MAX_SIZE = 10;   //仓库大小

const int SIZE_OF_PRODUCTOR = 3;//生产者数量
const int SIZE_OF_CONSUMER  = 3;//消费者数量

int iCountProduct;              //生产量计数
int iCountConsume;              //消费量计数

using namespace std;

queue<int> g_qRepo;
CRITICAL_SECTION g_csRepo;

DWORD WINAPI ProductTask(LPVOID param)
{
    while(TRUE)
    {
        Sleep(rand()/RAND_MAX);
        EnterCriticalSection(&g_csRepo);
        if (iCountProduct == ITEM_QUATITY)
        {
            cout << "生产计划完成" << endl;
            LeaveCriticalSection(&g_csRepo);
            return ;
        }

        if (g_qRepo.size() == REPO_MAX_SIZE)
        {
            cout << "仓库已经满了" << endl;
            LeaveCriticalSection(&g_csRepo);
            continue;
        }
        
    }

    return NULL;
}

DWORD WINAPI ConsumeTask(LPVOID param)
{
    while (TRUE)
    {
        if (g_qRepo.empty())
        {
        }
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

