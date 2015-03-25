#include "Humain.hpp"

Humain::Humain(const sf::Vector2f& position,const string& str,Map & __map, EventManager & _em):Personnage(position,str,__map,_em)
{
    //ctor
}

Humain::~Humain()
{
    //dtor
}
void Humain::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    Personnage::draw(target,states);
}
