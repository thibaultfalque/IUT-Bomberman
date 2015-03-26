#include "Sol.hpp"

Sol::Sol(string str,bool b,sf::Vector2f pos):Case(str,b,pos)
{
   _bonusMalus=nullptr;
   _bomb=nullptr;
}

Sol::~Sol()
{
    delete _bonusMalus;
}
void Sol::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    Case::draw(target,states);
    if(_bomb!=nullptr)
        target.draw(*_bomb);
}
BonusMalus* Sol::getBonusMalus(){
    return _bonusMalus;
}
void Sol::setBonusMalus(BonusMalus* bm){
    _bonusMalus=bm;
}
void Sol::setBomb(Bomb* b){
    if(_bomb==nullptr){
        _bomb=b;
        _bomb->setPosition(sf::Vector2f(_pos.x+LARGEUR/4,_pos.y+HAUTEUR/4));
    }
}
