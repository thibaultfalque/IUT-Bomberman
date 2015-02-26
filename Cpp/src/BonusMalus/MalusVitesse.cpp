#include "MalusVitesse.hpp"

MalusVitesse::MalusVitesse():BonusMalus()
{
    //ctor
}

void MalusVitesse::action(Personnage* perso){
    //ici je définis qu'on diminue la vitesse de déplacement de 10, peut etre modifié après tests
    perso->setVitesse(sf::Vector2f(perso->getVitesse().x-10,perso->getVitesse().y-10));
    //ici je définis que la vitesse min est 10, peut etre modifié après tests
    if(perso->getVitesse().x<10)
        perso->setVitesse(sf::Vector2f(10,10));
}

MalusVitesse::~MalusVitesse()
{
    //dtor
}
