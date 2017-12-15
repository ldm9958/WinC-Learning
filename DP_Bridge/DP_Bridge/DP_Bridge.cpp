// DP_Bridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "DP_Bridge.h"

using namespace std;

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

Linux::Linux()
{

}

Linux::~Linux()
{

}

void Linux::doplay()
{
    cout << "Linux" <<endl;
}

Windows::Windows()
{

}

Windows::~Windows()
{

}

void Windows::doplay()
{
    cout << "Windows" <<endl;
}

Unix::Unix()
{

}

void Unix::doplay()
{
    cout << "Unix" <<endl;
}

Player::Player()
{

}

Player::~Player()
{

}

void Player::setOS(OperateSystem * os)
{
    Os = os;
}

MP3Player::MP3Player()
{

}

MP3Player::~MP3Player()
{

}

void MP3Player::play()
{
    cout << "playing mp3 on ";
    Os->doplay();
}

WMAPlayer::WMAPlayer()
{

}

WMAPlayer::~WMAPlayer()
{

}

void WMAPlayer::play()
{
    cout << "playing WMA on ";
    Os->doplay();
}

WAVPlayer::WAVPlayer()
{

}

WAVPlayer::~WAVPlayer()
{

}

void WAVPlayer::play()
{
    cout << "playing WAV on ";
    Os->doplay();
}

OperateSystem::OperateSystem()
{

}

OperateSystem::~OperateSystem()
{

}
