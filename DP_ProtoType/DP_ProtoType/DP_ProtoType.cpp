// DP_ProtoType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "DP_ProtoType.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    Book bkMy = Book(10);
    Book bkMy2 = bkMy;

    bkMy.ShowPage();
    bkMy2.ShowPage();
    bkMy.ShowAddress();
    bkMy2.ShowAddress();

    system("pause");

	return 0;
}

Book::Book(int iPages)
{
   m_stcA = new STC_BOOK;
   m_stcA->iPages = iPages;
}

Book::Book(const Book& book)
{
    m_stcA = new STC_BOOK;
    m_stcA->iPages = book.m_stcA->iPages;
    strcpy(m_stcA->pTitle,book.m_stcA->pTitle);
}

void Book::ShowAddress()
{     
    cout<<"address:"<<(int *)&m_stcA<<endl;
}

Book::~Book()
{
    if (m_stcA != NULL)
    {
        delete m_stcA;
        m_stcA = NULL;
    }
}

void Book::ShowPage()
{
    if (m_stcA == NULL)
    {
        wprintf(L"NULL...");
        return ;
    }
    cout<<"pages total"<<m_stcA->iPages<<endl;
}

void Book::SetPage(int iPages)
{
    m_stcA->iPages = iPages;
}
