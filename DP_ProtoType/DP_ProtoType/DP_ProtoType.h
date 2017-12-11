#include "stdafx.h"
#include <cstring>

typedef struct _STC_BOOK
{
    int iPages;
    char pTitle[50];
    _STC_BOOK()
    {
        iPages = 2;
        memset(pTitle,0,sizeof(pTitle));
    }
}STC_BOOK,*PSTC_BOOK;

class Book
{
private:
    PSTC_BOOK m_stcA;    

public:
    Book(int iPages);
    ~Book();
    Book(const Book& book); 

    void ShowAddress();

    void ShowPage();
    void SetPage(int iPages);
};