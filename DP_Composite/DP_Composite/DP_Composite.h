#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Tree
{
public:
    string m_strName;

    Tree(string name):m_strName(name){};
    ~Tree();
   
    
    vector<Tree*> m_vecTree;
    void ShowName();
    void Add(Tree * component);
    void Del(Tree * component);
    void GetAll();
};

class Box:public Tree
{
public:
    string m_strName;

    Box(string name):Tree(name){};
    ~Box();

    Tree * GetComponent(int iIndex);
    
};