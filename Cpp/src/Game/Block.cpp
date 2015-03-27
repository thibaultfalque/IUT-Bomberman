#include "Block.hpp"

Block::Block(string str,bool b,sf::Vector2f pos):Case(str,b,pos)
{

}

Block::~Block()
{
    //dtor
}
void Block::exploser(){}
void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    Case::draw(target,states);
}
