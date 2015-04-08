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
        virtual ~Menu();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        virtual void updateObs(sf::Time& tps);
        Background _background;
};

#endif // MENU_HPP
