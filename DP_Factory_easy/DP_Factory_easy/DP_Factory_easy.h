#include "stdafx.h"
#include <iostream>

class componant
{
public:
    componant();
    ~componant();

    virtual void act(){};
};

class wind : public componant
{
public:
    wind();
    ~wind();
    virtual void act();
};

class water : public componant
{
public:
    water();
    ~water();
    virtual void act();
};

class Factory
{
private:
    static Factory * m_fac;
    
    Factory();
    ~Factory();
    Factory(const Factory &);
public:    
    static Factory * instance();
    componant* CreateElement(int iType);
};

Factory * Factory::m_fac = new Factory();