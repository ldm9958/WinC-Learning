// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

int WINAPI add(int a,int b)
{
    return a+b;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	return TRUE;
}

