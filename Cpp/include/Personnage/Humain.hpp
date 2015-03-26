#ifndef HUMAIN_HPP
#define HUMAIN_HPP

#include "Personnage.hpp"
class Humain:public Personnage
{
    public:
        /** Default constructor */
        Humain(const sf::Vector2f& position,const string& str,Map & __map, EventManager & _em,BombManager & bm);
        /** Default destructor */
        virtual ~Humain();
        void update();
        void onEvent(sf::Event & event);
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        EventManager & _eventManager;

};

#endif // HUMAIN_HPP
