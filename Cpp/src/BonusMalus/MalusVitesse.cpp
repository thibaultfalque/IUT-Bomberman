#include "MalusVitesse.hpp"
#include "Personnage.hpp"

MalusVitesse::MalusVitesse(Vector2i pos,Vector2i graphicPos):BonusMalus(pos,graphicPos,"malusspeed.png")
{
    //ctor
}

void MalusVitesse::action(Personnage* perso){
    perso->setVitesse(perso->getVitesse()-20);
}

MalusVitesse::~MalusVitesse()
{
    //dtor
}
