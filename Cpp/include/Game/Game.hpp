#ifndef GAME_HPP
#define GAME_HPP

#include "header.hpp"
#include "General.hpp"
#include "Map.hpp"
#include "Background.h"
#include "Personnage/Humain.hpp"
#include "General/EventManager.hpp"
#include "BombManager.hpp"

class Game:public Screen
{
    public:
        /** Default constructor */
        Game(sf::Vector2i* s);
        /** Default destructor */
        virtual ~Game();
        void update();
        void onEvent(sf::Event & event);
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        Map _map;


        vector<vector<int>> _mapDangerousZone;
        sf::Vector2i* _window_size;
        Background _background;
        sf::RectangleShape statRec;

        EventManager _eventManager;
        BombManager _bombManager;
        Humain p_test;
};

#endif // GAME_HPP
