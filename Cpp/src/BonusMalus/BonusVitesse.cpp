#include "BonusVitesse.hpp"
#include "Personnage.hpp"
BonusVitesse::BonusVitesse(Vector2i pos,Vector2i graphicPos):BonusMalus(pos,graphicPos,"bonusspeed.png")
{
    //ctor
}

void BonusVitesse::action(Personnage* perso){
    //ici je définis qu'on augmente la vitesse de déplacement de 10, peut etre modifié après tests
    perso->setVitesse(perso->getVitesse()+20.0);
}

BonusVitesse::~BonusVitesse()
{
    //dtor
}
