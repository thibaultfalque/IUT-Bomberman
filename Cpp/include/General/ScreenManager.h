#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>


#include "Screen.h"
#include "General/Console.hpp"

using namespace std;
using namespace sf;

class ScreenManager
{
    public:
        static void goToScreen(string str);
        static void add(Screen& s,string str);
        static Screen screeCourant;
    protected:
    private:
        static map<string,Screen> _screen;

};

#endif // SCREENMANAGER_H
