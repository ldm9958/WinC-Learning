
#include "stdafx.h"
#include <iostream>

using namespace std;

typedef void(*Fun)(void);

class Base
{
    virtual void f(){cout <<"base::f"<<endl;}
    virtual void g(){cout <<"base::g"<<endl;}
    virtual void h(){cout <<"base::h"<<endl;}
};

class Son : public Base
{
    virtual void f1(){cout <<"Son::f"<<endl;}
    virtual void g1(){cout <<"Son::g"<<endl;}
    virtual void h1(){cout <<"Son::h"<<endl;}
};

