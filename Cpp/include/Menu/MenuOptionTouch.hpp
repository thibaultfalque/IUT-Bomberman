#ifndef MENUOPTIONTOUCH_HPP
#define MENUOPTIONTOUCH_HPP

#include "General/EventManager.hpp"
#include "header.hpp"
#include "Menu.hpp"
#include "InputKey.hpp"
class MenuOptionTouch:public Menu
{
    public:
        MenuOptionTouch(sf::Vector2i* s,EventManager& eventManager);
        virtual ~MenuOptionTouch();
    protected:
    private:
        EventManager& _event;
};

#endif // MENUOPTIONTOUCH_HPP
