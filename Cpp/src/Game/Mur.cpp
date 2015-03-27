#include "Mur.hpp"

Mur::Mur(string str,bool b,sf::Vector2f pos):Case(str,b,pos)
{

}

Mur::~Mur()
{
    //dtor
}
void Mur::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    Case::draw(target,states);
}
