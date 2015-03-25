#ifndef BOMB_HPP
#define BOMB_HPP
#include "header.hpp"
#include "Background.h"
class Bomb
{
    public:
        Bomb(string tex,Vector2f const& position, int puissance);
        virtual ~Bomb();
    protected:
        void countdown();
        void explode();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        int power;
        sf::Vector2f position,taille;
        sf::Sprite sprite;
};

#endif // BOMB_HPP
