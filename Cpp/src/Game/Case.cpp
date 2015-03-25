#include "Case.hpp"

Case::Case(string str,bool b,sf::Vector2f pos):_str(str),_canWalk(b),_pos(pos)
{
    _sprite=Ressource::getSprite(_str,IntRect(0,0,0,0));
    _sprite.setPosition(_pos);
}

Case::~Case()
{
    //dtor
}
bool Case::canWalk(){
    return _canWalk;
}
void Case::setCanWalk(bool b){
    _canWalk=b;
}
void Case::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_sprite,states);
}
void Case::setPosition(const sf::Vector2f& position){
    _pos=position;
}
