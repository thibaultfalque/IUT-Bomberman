#include "MalusNbBombes.hpp"
#include "Personnage.hpp"

MalusNbBombes::MalusNbBombes():BonusMalus()
{
    //ctor
}

void MalusNbBombes::action(Personnage* perso){
    perso->setnbBombeMax(perso->getnbBombeMax()-1);
    perso->setnbBombe(perso->getnbBombe()-1);
    if(perso->getnbBombeMax()<1){
        perso->setnbBombeMax(1);
        perso->setnbBombe(1);
    }
}

MalusNbBombes::~MalusNbBombes()
{
    //dtor
}
