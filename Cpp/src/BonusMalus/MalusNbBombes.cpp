#include "MalusNbBombes.hpp"
#include "Personnage.hpp"

MalusNbBombes::MalusNbBombes(Vector2i pos,Vector2i graphicPos):BonusMalus(pos,graphicPos,"malusbombe.png")
{
    //ctor
}

void MalusNbBombes::action(Personnage* perso){
    if(perso->setnbBombeMax(perso->getnbBombeMax()-1)){
    perso->removeBombe();
    cout << "REMOVE BOMBE" << endl;
    }
}

MalusNbBombes::~MalusNbBombes()
{
    //dtor
}
