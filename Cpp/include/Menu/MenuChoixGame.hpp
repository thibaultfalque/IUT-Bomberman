#ifndef MENUCHOIXGAME_HPP
#define MENUCHOIXGAME_HPP

#include "Menu.hpp"
#include "ViewLevel.hpp"
#include "ChoixLevel.hpp"


class MenuChoixGame:public Menu
{
    public:
        /** Default constructor */
        MenuChoixGame(sf::Vector2i* s,EventManager& event);
        /** Default destructor */
        virtual ~MenuChoixGame();
        virtual void onEvent(sf::Event & event);
        virtual void update(sf::Time& tps);
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        map<string,string> typeDescription;
        sf::Text labelDescription;
        sf::Text description;

        bool _hover;
        string buttonHover;


};

#endif // MENUCHOIXGAME_HPP
