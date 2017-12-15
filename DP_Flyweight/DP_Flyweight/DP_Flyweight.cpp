// DP_Flyweight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DP_Flyweight.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    Ground* ground = Ground::GetInstance();
    Factory* fc = Factory::GetInstance();

    Chess* chess = fc->GetChess(BLACK);
    chess->SetPoint(10,10);          // 第一手天元 - -
    ground->DrawChess(*chess);

    chess = fc->GetChess(WHITE);
    chess->SetPoint(13,6);
    ground->DrawChess(*chess);

    chess = fc->GetChess(BLACK);
    chess->SetPoint(2,7);
    ground->DrawChess(*chess);

    chess = fc->GetChess(WHITE);
    chess->SetPoint(9,3);
    ground->DrawChess(*chess);

    ground->ShowAllChess();
	return 0;
}

void Chess::SetPoint(int x,int y)
{
    m_point.point_x = x;
    m_point.point_y = y;
}

void Chess::Show()
{
    if (m_color == BLACK)
    {
        cout << "black chess";
    }
    else
    {
        cout << "white chess";
    }

    cout<< " at (" << m_point.point_x << "," << m_point.point_y <<")" << endl; 
    
}

COLOR Chess::GetColor()
{
    return m_color;
}

Ground::Ground()
{

}

Ground * Ground::GetInstance()
{
    return instance;
}

void Ground::DrawChess(Chess chess)
{
    m_vecChess.push_back(chess);
    cout << "draw";
    if (chess.GetColor() == WHITE)
    {
        cout << " white chess ";
    }
    else
    {
        cout << " black chess ";
    }
    cout <<"(" << chess.m_point.point_x << "," << chess.m_point.point_y << ")" << endl;
}

void Ground::ShowAllChess()
{   
    cout << "show all chesses" <<endl;
    if (m_vecChess.empty())
    {
        return;
    }
    
    for(vector<Chess>::iterator iter = m_vecChess.begin();iter != m_vecChess.end();iter++)
    {
        iter->Show();
    }
}

Factory::Factory()
{

}

Chess* Factory::GetChess(COLOR color)
{
    if (m_vecChess.empty())
    {
        Chess* chess = new Chess(color);
        m_vecChess.push_back(chess);
        return chess;
    }

    for (vector<Chess*>::iterator iter = m_vecChess.begin();iter != m_vecChess.end();iter++)
    {
        if ((*iter)->GetColor() == color)
        {
            return *iter;
        }
    }

    Chess* chess = new Chess(color);
    m_vecChess.push_back(chess);
    return chess;
}

Factory * Factory::GetInstance()
{
    return instance;
}
