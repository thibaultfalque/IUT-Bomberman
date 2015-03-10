#ifndef GAME_HPP
#define GAME_HPP

#include "header.hpp"
#include "General.hpp"
#include "Map.hpp"

class Game:public Screen
{
    public:
        /** Default constructor */
        Game(sf::Vector2i* s);
        /** Default destructor */
        virtual ~Game();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        Map _map;
        sf::Vector2i* _window_size;
};

#endif // GAME_HPP
