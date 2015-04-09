#ifndef MENU_HPP
#define MENU_HPP

#include "header.hpp"
#include "General/Screen.h"
#include "Bouton.hpp"
#include "Background.h"

#include <string>
using namespace sf;
class Menu: public Screen
{
    public:
        Menu(sf::Vector2i* s);
        virtual void onEvent(sf::Event & event);
        virtual void update(sf::Time& tps);
        void addObs(string str,Observateur* ob);
        void removeObs(Observateur* ob);
        void updateObs();
        virtual ~Menu();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        map<string,Observateur*> _gui;
        Background _background;
    private:
        virtual void updateObs(sf::Time& tps);


};

#endif // MENU_HPP
