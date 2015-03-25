#include "Humain.hpp"

Humain::Humain(const sf::Vector2f& position,const string& str):Personnage(position,str)
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
