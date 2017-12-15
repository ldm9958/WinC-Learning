// DP_Composite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DP_Composite.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    Box room = Box("room");
    Box* bigbox = new Box("bigbox");
    Box* smallbox = new Box("smallbox");
    Box* apple = new Box("apple");
    Box* banana = new Box("banana");
    Box* orange = new Box("orange");
    Box* pear = new Box("pear");

    room.Add(bigbox);
    room.Add(smallbox);

    bigbox->Add(apple);
    bigbox->Add(banana);

    smallbox->Add(orange);
    smallbox->Add(pear);

    room.GetAll();
    smallbox->Del(orange);
    room.GetAll();
	return 0;
}

Tree::~Tree()
{
    m_vecTree.clear();
}

void Tree::Add(Tree * component)
{
    m_vecTree.push_back(component);
}

void Tree::Del(Tree * component)
{
    for (vector<Tree*>::iterator iter = m_vecTree.begin();iter!=m_vecTree.end();iter++)
    {
        if ((*iter)->m_strName == component->m_strName)
        {
            m_vecTree.erase(iter);
            return ;
        }
    }

//    m_vecTree.erase(&component);
}

Box::~Box()
{

}

Tree * Box::GetComponent(int iIndex)
{
    if (m_vecTree.size() >= iIndex)
    {
        return m_vecTree[iIndex];
    }

    return NULL;
}

void Tree::ShowName()
{
    cout << m_strName << endl;
}

void Tree::GetAll()
{
    ShowName();
    
    if (!m_vecTree.empty())
    {     
        for (vector<Tree*>::iterator iter=m_vecTree.begin();iter!=m_vecTree.end();iter++)
        {
            cout <<"    ";
            (*iter)->GetAll();
        }
    }
}
