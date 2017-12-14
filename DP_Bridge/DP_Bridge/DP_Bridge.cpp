// DP_Bridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

using std::string;

class OperatinSystem {
public:
    OperatinSystem (){};
    virtual ~OperatinSystem (){};
    virtual void doPlay() = 0;
};

class Linux : public OperatinSystem {
public:
    Linux  (){};
    virtual ~Linux(){};
    virtual void doPlay(){
        std::cout << " Linux" << std::endl;
    }
};

class Unix : public OperatinSystem {
public:
    Unix(){};
    virtual ~Unix(){};
    virtual void doPlay(){
        std::cout << " Unix" << std::endl;
    }
};

class Windows : public OperatinSystem {
public:
    Windows  (){};
    virtual ~Windows(){};
    virtual void doPlay(){
        std::cout << " Windows" << std::endl;
    }
};

class Player {
protected:
    OperatinSystem *OS;
public:
    Player (): OS(NULL){};
    virtual void setOS(OperatinSystem *os){OS = os;}
    virtual ~Player (){};

    virtual void play() = 0;
};

class MP3Player : public Player{
public:
    MP3Player(){};
    virtual ~MP3Player(){};
    virtual void play(){
        std::cout << "Play MP3 under ";
        OS->doPlay();
    }
};

class WAVPlayer : public Player{
public:
    WAVPlayer(){};
    virtual ~WAVPlayer(){};
    virtual void play(){
        std::cout << "Play WAV under ";
        OS->doPlay();
    }
};

class WMAPlayer : public Player{
public:
    WMAPlayer(){};
    virtual ~WMAPlayer(){};
    virtual void play(){
        std::cout << "Play WMA under ";
        OS->doPlay();
    }
};

int main(void)
{
    Player *mp3Player = new MP3Player;
    mp3Player->setOS(new Linux);
    mp3Player->play();
    mp3Player->setOS(new Windows);
    mp3Player->play();
    mp3Player->setOS(new Unix);
    mp3Player->play();

    Player *wmalayer = new WMAPlayer;
    wmalayer->setOS(new Linux);
    wmalayer->play();
    wmalayer->setOS(new Windows);
    wmalayer->play();
    wmalayer->setOS(new Unix);
    wmalayer->play();

    Player *wavPlayer = new WAVPlayer;
    wavPlayer->setOS(new Linux);
    wavPlayer->play();
    wavPlayer->setOS(new Windows);
    wavPlayer->play();
    wavPlayer->setOS(new Unix);
    wavPlayer->play();

    system("pause");
}

