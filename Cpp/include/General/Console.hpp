#ifndef CONSOLE_H
#define CONSOLE_H

//CATEGORIES DEFINES

#define MSG_DEFAULT 0
#define MSG_ERROR 1
#define MSG_TCHAT 2

#include <SFML/Graphics.hpp>
#include <list>

using namespace std;
using namespace sf;



struct dbg_msg
{
    Clock date;  //Peut éventuellement servir à mettre une date de péremption au message. (Effacer un message au bout d'un certain temps...). Non implémenté.
    Text msg;
    unsigned int categorie;
};

class Console
{
private:
    static RectangleShape background;
    static list<dbg_msg> messages;
    static void deleteOneMessage();
public:
    static void draw(sf::RenderTarget& target, sf::RenderStates states);
    static void say(String message,unsigned int categorie=MSG_DEFAULT);

};
#endif // CONSOLE_HPP
