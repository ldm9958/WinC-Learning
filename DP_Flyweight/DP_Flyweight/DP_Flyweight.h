#pragma once

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

typedef enum color
{
    BLACK,
    WHITE,
}COLOR;

typedef struct point
{
    int point_x;
    int point_y;
}POINT;

class Chess
{
public:
    COLOR m_color;  //in
    POINT m_point;  //out
    Chess(COLOR color):m_color(color){};
    void SetPoint(int x,int y);
    void Show();
    COLOR GetColor();
};

class Factory
{
private:
    static Factory * instance;
    Factory();
    ~Factory();
    Factory operator =  (Factory &);
public:
    vector<Chess*> m_vecChess;
    Chess* GetChess(COLOR color);
    static Factory * GetInstance();
};  

Factory* Factory::instance = new Factory();

class Ground
{
private:
    static Ground * instance;

    Ground();
    ~Ground();
    Ground operator = (Ground &);
public:
    
    int m_sizex;
    int m_sizey;
    vector<Chess> m_vecChess;
    static Ground * GetInstance();
    void DrawChess(Chess chess);
    void ShowAllChess();
};

Ground* Ground::instance = new Ground;