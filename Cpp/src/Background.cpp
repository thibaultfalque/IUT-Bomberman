#include "Background.h"

Background::Background(string str)
{
    if(str=="")
        _str="default.png";
    else
        _str=str;
}

Background::~Background()
{
    //dtor
}
void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(Ressource::getSprite(_str,IntRect(0,0,0,0)),states);
}
