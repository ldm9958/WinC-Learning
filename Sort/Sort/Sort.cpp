// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

// 获取系统的当前时间，单位微秒(us)
LONGLONG GetSysTimeMicros()
{
	// 从1601年1月1日0:0:0:000到1970年1月1日0:0:0:000的时间(单位100ns)
#define EPOCHFILETIME   (116444736000000000UL)
	FILETIME ft;
	LARGE_INTEGER li;
	LONGLONG tt = 0;
	GetSystemTimeAsFileTime(&ft);
	li.LowPart = ft.dwLowDateTime;
	li.HighPart = ft.dwHighDateTime;
	// 从1970年1月1日0:0:0:000到现在的微秒数(UTC时间)
	tt = (li.QuadPart - EPOCHFILETIME) /10;
	return tt;
}

int iArr[]={2,4,6,1,7,5,10,8,3,9,12,11};

void swap(int &a,int &b)
{
	int iTemp = a; 
	a = b;
	b = iTemp;
}

void PrintArray(const int *iArray,const int iCount)
{
	for (int i = 0;i<iCount;i++)
	{
		printf("%d ",iArray[i]);
	}
	printf("\n");
}

void BubbleSort(int *iArray,const int iCount)
{
	for (int i = 0;i< iCount - 1;i++)
	{
		for (int j = i+1;j<iCount;j++ )
		{
			if (iArray[i] <= iArray[j])
			{
				swap(iArray[i],iArray[j]);
			}
		}
	}
}

void QuickSort(int *iArray,const int iLeft,const int iRight)
{
	if (iLeft>=iRight)
	{
		return;
	}
	int i = iLeft;
	int k = iRight;
	//int iLeft = iArray[0];
	//int iRight = iArray[iCount-1];
	//int iTemp = iArray[0];

	while (i < k)
	{
		while(i < k && iArray[k]>iArray[i])
		{
			k--;
		}
		swap(iArray[k],iArray[i]);
		while (i < k && iArray[k]>iArray[i])
		{
			i++;
		}
		swap(iArray[k],iArray[i]);
	}

	QuickSort(iArray,iLeft,i);
	QuickSort(iArray,i+1,iRight);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int iArray1[24] = {2,4,6,1,7,5,10,8,3,9,12,11,34,51,123,413,122,23,64,88,33,144,189,422};
	int iArray2[24] = {2,4,6,1,7,5,10,8,3,9,12,11,34,51,123,413,122,23,64,88,33,144,189,422};

	LONGLONG llStart = GetSysTimeMicros();
	PrintArray(iArray1,24);
	BubbleSort(iArray1,24);
	PrintArray(iArray1,24);	
	LONGLONG llEnd = GetSysTimeMicros();
	cout <<"bubble sort over,begin:" << llStart << "end: "<< llEnd <<"cost" <<(LONGLONG)(llEnd-llStart)<<endl;

	llStart = GetSysTimeMicros();

	PrintArray(iArray2,24);
	QuickSort(iArray2,0,23);
	PrintArray(iArray2,24);
	llEnd = GetSysTimeMicros();
	cout <<"quick sort over,begin:"  << llStart << "end: "<< llEnd <<"cost" <<(LONGLONG)(llEnd-llStart)<<endl;

	getchar();
	return 0;
}

