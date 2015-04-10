#include "BonusNbBombes.hpp"
#include "Personnage.hpp"
BonusNbBombes::BonusNbBombes(Vector2i pos,Vector2i graphicPos):BonusMalus(pos,graphicPos,"bonusbombe.png")
{
    //ctor
}

void BonusNbBombes::action(Personnage* perso){
    if(perso->setnbBombeMax(perso->getnbBombeMax()+1)){
        perso->addBombe();
        cout << "AJOUT BOMBE" << endl;
    }
}

BonusNbBombes::~BonusNbBombes()
{
    //dtor
}
