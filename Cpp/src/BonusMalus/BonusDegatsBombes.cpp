#include "BonusDegatsBombes.hpp"

BonusDegatsBombes::BonusDegatsBombes():BonusMalus()
{
    //ctor
}

void BonusDegatsBombes::action(Personnage* perso){
    perso->setdegatsBombes(perso->getdegatsBombes()+2);
}

BonusDegatsBombes::~BonusDegatsBombes()
{
    //dtor
}
