#ifndef CHOIXLEVEL_HPP
#define CHOIXLEVEL_HPP

#include "header.hpp"
#include "General.hpp"
#include "Menu.hpp"
#include "ViewLevel.hpp"
#include "Game.hpp"
class ChoixLevel:public Menu
{
    public:
        /** Default constructor */
        ChoixLevel(sf::Vector2i* s,string dir,int type,EventManager& event);
        /** Default destructor */
        virtual ~ChoixLevel();
        void onEvent(sf::Event & event);
        void update(sf::Time& tps);

     protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
     vector<ViewLevel*> listLevel;
     ViewLevel* view[3];
     Bouton* _bouton;
     EventManager& eventManager;
};

#endif // CHOIXLEVEL_HPP
