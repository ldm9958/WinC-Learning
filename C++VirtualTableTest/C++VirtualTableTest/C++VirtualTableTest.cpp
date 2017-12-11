// C++VirtualTableTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "C++VirtualTableTest.h"

int _tmain(int argc, _TCHAR* argv[])
{
    Base b;
    Fun pFun = NULL;    

    cout << "base虚函数表地址：" << (int*)(&b) << endl;
    cout << "base虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
 //   cout << "base虚函数表 — 第二个函数地址：" << (int*)*((int*)(&b)) << endl;

    pFun = (Fun)*((int*)*(int*)(&b));
    pFun();

    pFun = (Fun)*((int*)*((int*)(&b))+1);
    pFun();

    pFun = (Fun)*((int*)*((int*)(&b))+2);
    pFun();

    Son c;

    cout << "Son虚函数表地址：" << (int*)(&c) << endl;
    cout << "Son虚函数表 — 第一个函数地址：" << (int*)*(int*)(&c) << endl;

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

