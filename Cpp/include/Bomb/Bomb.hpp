#ifndef BOMB_HPP
#define BOMB_HPP
#include "header.hpp"
#include "Background.h"
#include "StratBombSimple.hpp"
#include "Map.hpp"
class Map;
class StratBombSimple;
class Personnage;
class Bomb:public sf::Drawable
{
    public:
        Bomb(Personnage & p, int puissance);
        Bomb(sf::Vector2i& mapPosition);
        virtual ~Bomb();
        vector<Vector2i> explode(Map& m);
        void setPosition(const sf::Vector2f& pos);
        void update(sf::Time tps);
        sf::Vector2i& getMapPosition();
        void setMapPosition(const sf::Vector2i& pos);
        bool mustExplode();
        int getPower();
        void getListCaseTouch(Map& _map,vector<vector<bool>>& tab);
        Personnage * getPersonnage();
        bool getPersonnageOut();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        int power;
        sf::Vector2f position,taille;
        sf::Vector2i _mapPosition;
        sf::Sprite sprite;
        float tempTotal;
        string textureName;
        StratBombSimple* stratBomb;
        bool _explosion;
        bool _personnageOut;
        Personnage * owner;

};

#endif // BOMB_HPP
