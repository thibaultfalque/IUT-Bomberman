#include "BonusVitesse.hpp"

BonusVitesse::BonusVitesse():BonusMalus()
{
    //ctor
}

void BonusVitesse::action(Personnage* perso){
    //ici je définis qu'on augmente la vitesse de déplacement de 10, peut etre modifié après tests
    perso->setVitesse(sf::Vector2f(perso->getVitesse().x+10,perso->getVitesse().y+10));
    //ici je définis que la vitesse max est 100, peut etre modifié après tests
    if(perso->getVitesse().x>100)
        perso->setVitesse(sf::Vector2f(100,100));
}

BonusVitesse::~BonusVitesse()
{
    //dtor
}
