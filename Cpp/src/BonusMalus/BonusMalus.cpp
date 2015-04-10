#include "BonusMalus.hpp"
#include "General/Ressource.hpp"

BonusMalus::BonusMalus(Vector2i pos,Vector2i graphicPos,string chm)
{
    _pos = pos;
    _sprite = Ressource::getSprite(chm);
    _sprite.setPosition(graphicPos.x,graphicPos.y);
}

void BonusMalus::action(Personnage* perso){}

BonusMalus::~BonusMalus()

{
    //dtor
}
Vector2i BonusMalus::getPos()
{
    return _pos;
}

void BonusMalus::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite,states);
}

FloatRect BonusMalus::getHitBox()
{
    return _sprite.getGlobalBounds();
}
