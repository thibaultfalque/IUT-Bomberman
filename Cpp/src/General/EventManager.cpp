#include "General/EventManager.hpp"

#include <iostream>
#include "noClass/fn_string.hpp"
#include "General/Console.hpp"
#include "noClass/fn_file.hpp"

using namespace sf;
using namespace std;

const std::string EventManager::KeyName[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
								 "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
								 "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Echap",
								 "Ctrl Gauche", "Shift Gauche", "Alt Gauche", "System Gauche",
								 "Ctrl Droit", "Shift Droit", "Alt Droit", "System Droit", "Menu",
								 "[", "]", ";", ",", ".", "'", "/", "\\", "~", "=", "-", "Espace",
								 "Entree", "Retour arriere", "Tabulation", "Page suiv.", "Page prec.",
								 "Fin", "Debut", "Insert", "Suppr", "+ Numpad", "- Numpad", "* Numpad", "/ Numpad", "Gauche", "Droite", "Haut",
								 "Bas", "0 Numpad", "1 Numpad", "2 Numpad", "3 Numpad", "4 Numpad", "5 Numpad", "6 Numpad", "7 Numpad", "8 Numpad", "9  Numpad",
								 "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15", "Pause"};

EventManager::EventManager(){


    makeDir("res");
    makeDir("res/config");
    initDefault();

    if(!loadFromFile("res/config/keyboard.cfg"))
    {
        Console::say(L"Erreur de chargement du fichier de configuration \ndes touches.",1);
        Console::say(L"La configuration des touches a été réinitialisée.",1);
        saveConfigurationFile();
    }
}

void EventManager::initDefault(){
    addEventConf("Gauche",Keyboard::Q);
    addEventConf("Droite",Keyboard::D);
    addEventConf("Haut",Keyboard::Z);
    addEventConf("Bas",Keyboard::S);
    addEventConf("Poser bombe",Keyboard::E);
    addEventConf("Menu",Keyboard::Escape);
}

bool EventManager::loadFromFile(string file){

        ifstream saveFile(file.c_str(), ios::in);

        if(!saveFile)
            return false;

        string line;
        vector<string> words;

        while(getline(saveFile, line)){
            words = explode(line,':');
            if(words.size()!=2)
                return false;

            addEventConf(words[0], (sf::Keyboard::Key)string_to_int(words[1]));
        }



        saveFile.close();

        return true;
}

bool EventManager::saveConfigurationFile(){
     ofstream saveFile("res/config/keyboard.cfg", ios::out | ios::trunc);

     if(!saveFile)
        return false;

    for(EventConf::iterator it=_eventconf.begin() ; it!=_eventconf.end() ; ++it)
    {
        saveFile << it->first << ':' << it->second << endl;;
    }

     saveFile.close();

     return true;
}

void EventManager::addEventConf(string str,Keyboard::Key key)
{
    if(_eventconf.find(str)==_eventconf.end() || _eventconf[str] != key)
    {   // cette condition réduit le nombre d'écriture dans le fichier
        _eventconf[str] = key;    //On crée ou met à jour la touche associée à un événement 'str'. Cette touche sera maintenant 'key'
        saveConfigurationFile();
    }
}

bool EventManager::getEventState(std::string str)
{
    return  _eventconf.find(str)!=_eventconf.end() && sf::Keyboard::isKeyPressed(_eventconf[str]); //Si la touche n'est pas trouvée on renvoit FALSE
}

Keyboard::Key EventManager::getEventKey(string str){
    if(_eventconf.find(str)!=_eventconf.end())
        return _eventconf[str];
    else
    {
        Console::say(L"L'évènement demandé \"" + str + L"\" n'a pas été trouvé dans le gestionnaire d'évènement", 1);
        return Keyboard::Key::Unknown;
    }
}

string EventManager::keyToString(Keyboard::Key key){
    if(key<0||key>=Keyboard::Key::KeyCount)
        return "Touche inconnue";

    return KeyName[key];
}


