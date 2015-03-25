#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP
#include "BonusMalus/BonusMalus.hpp"
#include "header.hpp"
#include "General.hpp"
class BonusMalus;
class Personnage:public sf::Drawable
{
    public:
        Personnage(sf::Vector2f position,const string& str);
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
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::Vector2f pos, vitesse;
        int nbBombeMax, nbBombe, degatsBombes;
        vector<BonusMalus> bonusMalus;
        bool launcher, pusher;
        sf::Sprite _sprite;
        //Bombe bombe;
    private:
};

#endif // PERSONNAGE_H
