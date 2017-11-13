// MultiProductorConsumerModel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <queue>

const int ITEM_QUATITY  = 100;  //��Ʒ�ƻ�����
const int REPO_MAX_SIZE = 10;   //�ֿ��С

const int SIZE_OF_PRODUCTOR = 3;//����������
const int SIZE_OF_CONSUMER  = 3;//����������

int iCountProduct;              //����������
int iCountConsume;              //����������

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
            cout << "�����ƻ����" << endl;
            LeaveCriticalSection(&g_csRepo);
            return ;
        }

        if (g_qRepo.size() == REPO_MAX_SIZE)
        {
            cout << "�ֿ��Ѿ�����" << endl;
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

