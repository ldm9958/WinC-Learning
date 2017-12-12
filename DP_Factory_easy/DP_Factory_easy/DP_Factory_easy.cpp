// DP_Factory_easy.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <Windows.h>
#include "DP_Factory_easy.h"

using namespace std;



wind::wind()
{

}

wind::~wind()
{

}

void wind::act()
{
    cout << "whooooo"<<endl;
}

water::water()
{

}

water::~water()
{

}

void water::act()
{
    cout << "lalala" <<endl;
}

Factory::Factory()
{

}

Factory::~Factory()
{
    if (m_fac!=NULL)
    {
        delete m_fac;
        m_fac = NULL;
    }
}

Factory * Factory::instance()
{
    return m_fac;
}

componant* Factory::CreateElement(int iType)
{
    componant* comp = NULL;
    switch(iType)
    {
    case 0:
        comp = new wind;
        break;
    case 1:
        comp = new water;
        break;
    default:
        break;
    }
    return comp;
}

int _tmain(int argc, _TCHAR* argv[])
{
    Factory *fact = Factory::instance();
    componant* comp1 = NULL;
    componant* comp2 = NULL;
    comp1 = fact->CreateElement(0);
    comp2 = fact->CreateElement(1);

    comp1->act();
    comp2->act();

    if (comp1 != NULL)
    {
        delete comp1;
        comp1 = NULL;
    }

    if (comp2 != NULL)
    {
        delete comp2;
        comp2 = NULL;
    }

    system("pause");
    return 0;
}

componant::componant()
{

}

componant::~componant()
{

}
