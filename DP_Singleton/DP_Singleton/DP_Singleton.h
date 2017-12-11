#include "stdafx.h"

class MyClass
{

private:
    static MyClass * m_instance;
    MyClass();
    ~MyClass();
    MyClass( const MyClass &);

public:
    static MyClass &Instance();
};