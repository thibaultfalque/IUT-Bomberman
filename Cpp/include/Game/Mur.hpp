#ifndef MUR_HPP
#define MUR_HPP

#include "Case.hpp"
class Mur:public Case
{
    public:
        /** Default constructor */
        Mur(string str,bool b,sf::Vector2f pos);
        /** Default destructor */
        virtual ~Mur();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
};

#endif // MUR_HPP
