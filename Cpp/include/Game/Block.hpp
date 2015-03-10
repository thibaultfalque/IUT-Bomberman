#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Case.hpp"
class Block:public Case
{
    public:
        /** Default constructor */
        Block(string str,bool b,sf::Vector2f pos);
        /** Default destructor */
        virtual ~Block();
        void exploser();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
};

#endif // SOL_HPP
