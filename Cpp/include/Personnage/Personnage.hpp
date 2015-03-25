#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP
#include "BonusMalus/BonusMalus.hpp"
#include "header.hpp"
#include "General/Ressource.hpp"
#include "General/Console.hpp"
#include "Game/Map.hpp"
#include "General/EventManager.hpp"
class BonusMalus;
class Map;
class Personnage : public sf::Drawable
{
    public:
        Personnage(sf::Vector2f position, Map & __map, EventManager & _em);
        virtual ~Personnage();
        void setVitesse(sf::Vector2f vitesse);
        void setnbBombeMax(int nbBombeMax);
        void setnbBombe(int nbBombe);
        void setdegatsBombes(int degatsBombes);
        void setLauncher(bool launcher);
        void setPusher(bool pusher);
        sf::Vector2f getPos();
        sf::Vector2f getVitesse();
        int getnbBombeMax();
        int getnbBombe();
        int getdegatsBombes();
        void addBonusMalus(BonusMalus b);
        void update();
        void moveTo(sf::Vector2f newPos);
        bool canMoveTo(sf::Vector2i newPos);
    protected:
        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
        sf::Vector2f pos, vitesse;
        int nbBombeMax, nbBombe, degatsBombes;
        vector<BonusMalus> bonusMalus;
        bool launcher, pusher;
        int etapePas;
        int direction;
        sf::Clock timerPas;
        sf::Clock deltaUpdate;
        sf::Sprite _sprites[4][9];
        Map & _map;
        EventManager & _eventManager;
        //Bombe bombe;
    private:
};

#endif // PERSONNAGE_H
