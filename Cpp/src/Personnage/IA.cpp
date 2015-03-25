#include "IA.hpp"

IA::IA(const sf::Vector2f& position,const string& str,Map & __map, EventManager & _em):Personnage(position,str,__map,_em)
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

