#ifndef HUMAIN_HPP
#define HUMAIN_HPP

#include "Personnage.hpp"
class Humain:public Personnage
{
    public:
        /** Default constructor */
        Humain(const sf::Vector2f& position,int numPersonnage,Map & __map, EventManager & _em,BombManager & bm);
        /** Default destructor */
        virtual ~Humain();
        virtual void update(sf::Time& tps);
        virtual void onEvent(sf::Event & event);
        virtual void putBomb();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        EventManager & _eventManager;

};

#endif // HUMAIN_HPP
