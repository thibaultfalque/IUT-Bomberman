#include "BonusPusher.h"

BonusPusher::BonusPusher():BonusMalus()
{
    //ctor
}

void BonusPusher::action(Personnage* perso){
    perso->setPusher(true);
}

BonusPusher::~BonusPusher()
{
    //dtor
}
