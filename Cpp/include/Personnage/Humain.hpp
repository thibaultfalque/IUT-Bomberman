#ifndef HUMAIN_HPP
#define HUMAIN_HPP

#include "Personnage.hpp"
class Humain:public Personnage
{
    public:
        /** Default constructor */
        Humain(const sf::Vector2f& position,const string& str,Map & __map, EventManager & _em);
        /** Default destructor */
        virtual ~Humain();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
};

#endif // HUMAIN_HPP
