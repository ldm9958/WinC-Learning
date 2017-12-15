
#include "stdafx.h"

class OperateSystem
{
public:
    OperateSystem();
    ~OperateSystem();
    virtual void    doplay()=0;
};

class Linux:public OperateSystem
{
public:
    Linux();
    ~Linux();
   virtual void doplay();
};

class Windows:public OperateSystem
{
public:
    Windows();
    ~Windows();
    virtual void doplay();
};

class Unix:public OperateSystem
{
public:
    Unix();
    ~Unix();
    virtual void doplay();
};

class Player
{
public:
    OperateSystem* Os;
    Player();
    ~Player();
    
    virtual void setOS(OperateSystem * os);
    virtual void play()=0;
};

class MP3Player:public Player
{
public:
    MP3Player();
    ~MP3Player();

    virtual void play();
};

class WMAPlayer:public Player
{
public:
    WMAPlayer();
    ~WMAPlayer();

    virtual void play();
};

class WAVPlayer:public Player
{
public:
    WAVPlayer();
    ~WAVPlayer();
    
    virtual void play();
};