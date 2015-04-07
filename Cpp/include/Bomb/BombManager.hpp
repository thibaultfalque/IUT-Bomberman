#ifndef BOMBMANAGER_HPP
#define BOMBMANAGER_HPP

#include "header.hpp"
#include "Bomb.hpp"
#include "Map.hpp"
#include "Personnage.hpp"
class BombManager
{
    public:
        BombManager(Map& m);
        virtual ~BombManager();
        bool hasBomb(const unsigned int x,const unsigned int y);
        bool putBomb(Personnage& p,Bomb* b);
        void testPutBomb(vector<vector<bool>>& dangerous,sf::Vector2i& mapPosition);
        //void explode();
        void draw(sf::RenderTarget& target,sf::RenderStates states) const;
        void update();
        void updateDangerous();
        vector<vector<bool>>* getTabDangerouseCase();

    protected:
    private:
        vector<vector<bool>> _dangerous;
        vector<Bomb*> _listbombe;
        vector<int> _eraseIndex;
        Map & _map;
        sf::Time tps;
        Clock clock;
};

#endif // BOMBMANAGER_HPP
