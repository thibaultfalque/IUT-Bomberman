#include "BonusNbBombes.hpp"
#include "Personnage.hpp"
BonusNbBombes::BonusNbBombes():BonusMalus()
{
    //ctor
}

void BonusNbBombes::action(Personnage* perso){
    perso->setnbBombeMax(perso->getnbBombeMax()+1);
    perso->setnbBombe(perso->getnbBombe()+1);
}

BonusNbBombes::~BonusNbBombes()
{
    //dtor
}
