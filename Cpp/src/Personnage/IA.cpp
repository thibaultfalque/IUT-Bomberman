#include "IA.hpp"

IA::IA(const sf::Vector2f& position,const string& str):Personnage(position,str)
{
    //ctor
}

IA::~IA()
{
    //dtor
}
void IA::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    Personnage::draw(target,states);
}

