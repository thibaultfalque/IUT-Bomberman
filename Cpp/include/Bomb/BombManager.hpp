#ifndef BOMBMANAGER_HPP
#define BOMBMANAGER_HPP

#include "header.hpp"
#include "Bomb.hpp"
#include "Map.hpp"
class BombManager
{
    public:
        BombManager(Map& m);
        virtual ~BombManager();
        bool hasBomb(const unsigned int x,const unsigned int y);
        void putBomb(const sf::Vector2i& mapPosition,const sf::Vector2f& screenPosition,Bomb* b);
        //void explode();
        void draw(sf::RenderTarget& target,sf::RenderStates states) const;
        void update();
    protected:
    private:
        vector<Bomb*> _listbombe;
        Map & _map;
        sf::Time tps;
        Clock clock;
};

#endif // BOMBMANAGER_HPP
