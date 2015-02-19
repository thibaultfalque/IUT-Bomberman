#include "General/ScreenManager.h"

map <string,Screen*> ScreenManager::_screen;

Screen* ScreenManager::screeCourant;

void ScreenManager::goToScreen(string str)
{
    if(_screen.find(str)!=_screen.end())
        screeCourant=_screen[str];

    else
        Console::say(L"Cet écran "+str+L" n'existe pas ",MSG_ERROR);
}

void ScreenManager::add(Screen* s,string str){
    _screen[str]=s;
}

