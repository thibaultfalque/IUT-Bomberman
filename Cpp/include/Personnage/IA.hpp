#ifndef IA_HPP
#define IA_HPP

#include "Personnage.hpp"
class IA:public Personnage
{
    public:
        /** Default constructor */
        IA(const sf::Vector2f& position,const string& str,Map & __map, EventManager & _em);
        /** Default destructor */
        virtual ~IA();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
};

#endif // IA_HPP
