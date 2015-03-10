#include "Sol.hpp"

Sol::Sol(string str,bool b,sf::Vector2f pos):Case(str,b,pos)
{
   _bonusMalus=nullptr;
}

Sol::~Sol()
{
    delete _bonusMalus;
}
void Sol::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    Case::draw(target,states);
}
BonusMalus* Sol::getBonusMalus(){
    return _bonusMalus;
}
void Sol::setBonusMalus(BonusMalus* bm){
    _bonusMalus=bm;
}
