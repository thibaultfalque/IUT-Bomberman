#include "BonusLauncher.hpp"

BonusLauncher::BonusLauncher():BonusMalus()
{
    //ctor
}

void BonusLauncher::action(Personnage* perso){
    perso->setLauncher(true);
}

BonusLauncher::~BonusLauncher()
{
    //dtor
}
