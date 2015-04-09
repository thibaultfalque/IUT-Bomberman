#ifndef MENUPAUSE_HPP
#define MENUPAUSE_HPP

#include "Menu.hpp"

class MenuPause:public Menu
{
    public:
        /** Default constructor */
        MenuPause(sf::Vector2i* s);
        /** Default destructor */
        virtual ~MenuPause();
    protected:
    private:
};

#endif // MENUPAUSE_HPP
