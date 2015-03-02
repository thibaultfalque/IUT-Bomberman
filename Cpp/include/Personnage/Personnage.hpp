#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP
#include "BonusMalus/BonusMalus.hpp"
#include "header.hpp"

class BonusMalus;
class Personnage
{
    public:
        Personnage(sf::Vector2f position);
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
    protected:
        sf::Vector2f pos, vitesse;
        int nbBombeMax, nbBombe, degatsBombes;
        vector<BonusMalus> bonusMalus;
        bool launcher, pusher;
        //Bombe bombe;
    private:
};

#endif // PERSONNAGE_H
