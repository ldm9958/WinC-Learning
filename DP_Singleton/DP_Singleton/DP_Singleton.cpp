// DP_Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "DP_Singleton.h"

CRITICAL_SECTION g_csLock;

using namespace std;

MyClass *MyClass::m_instance = NULL;

int _tmain(int argc, _TCHAR* argv[])
{
    InitializeCriticalSection(&g_csLock);
    MyClass &mcA = MyClass::Instance();
    MyClass &mcB = MyClass::Instance();
	return 0;
}

MyClass::MyClass()
{

}

MyClass::MyClass(const MyClass &)
{

}

MyClass::~MyClass()
{

}

MyClass & MyClass::Instance()
{
    if (m_instance == NULL)
    {
        EnterCriticalSection(&g_csLock);
        if (m_instance == NULL)
        {
            cout<< "first contribute..."<<endl;
            m_instance = new MyClass;
        }
        LeaveCriticalSection(&g_csLock);
    }
    cout<< "directivelly return..."<<endl;
    return *m_instance;
}

