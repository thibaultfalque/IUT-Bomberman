#ifndef MENU_HPP
#define MENU_HPP

#include "Observable.hpp"
#include "General/Screen.h"
#include "Bouton.hpp"

#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
class Menu: public Observable, public Screen
{
    public:
        Menu(sf::Vector2i* s);
        void onEvent(sf::Event & event);
        void update();
        void updateObs();
        virtual ~Menu();

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
    private:
};

#endif // MENU_HPP
