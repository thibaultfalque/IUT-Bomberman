#include "MalusDegatsBombes.hpp"

MalusDegatsBombes::MalusDegatsBombes():BonusMalus()
{
    //ctor
}

void MalusDegatsBombes::action(Personnage* perso){
    perso->setdegatsBombes(perso->getdegatsBombes()-2);
}

MalusDegatsBombes::~MalusDegatsBombes()
{
    //dtor
}
