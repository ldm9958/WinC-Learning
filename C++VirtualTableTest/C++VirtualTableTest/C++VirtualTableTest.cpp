// C++VirtualTableTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "C++VirtualTableTest.h"

int _tmain(int argc, _TCHAR* argv[])
{
    Base b;
    Fun pFun = NULL;    

    cout << "base�麯�����ַ��" << (int*)(&b) << endl;
    cout << "base�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&b) << endl;
 //   cout << "base�麯���� �� �ڶ���������ַ��" << (int*)*((int*)(&b)) << endl;

    pFun = (Fun)*((int*)*(int*)(&b));
    pFun();

    pFun = (Fun)*((int*)*((int*)(&b))+1);
    pFun();

    pFun = (Fun)*((int*)*((int*)(&b))+2);
    pFun();

    Son c;

    cout << "Son�麯�����ַ��" << (int*)(&c) << endl;
    cout << "Son�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&c) << endl;

    pFun = (Fun)*((int*)*((int*)(&c)));
    pFun();

    pFun = (Fun)*((int*)*((int*)(&c))+1);
    pFun();

    pFun = (Fun)*((int*)*((int*)(&c))+2);
    pFun();

    pFun = (Fun)*((int*)*((int*)(&c))+3);
    pFun();

    pFun = (Fun)*((int*)*((int*)(&c))+4);
    pFun();

    pFun = (Fun)*((int*)*((int*)(&c))+5);
    pFun();

	return 0;
}

