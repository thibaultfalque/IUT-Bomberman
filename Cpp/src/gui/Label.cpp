#include "Label.hpp"

Label::Label(sf::String str,sf::Vector2f position,float tailleCharacter,const sf::Color& color)
{
    _text.setFont(Ressource::getFont("default.ttf"));
    _text.setCharacterSize(tailleCharacter);
    _text.setColor(color);
    _text.setString(str);
    _text.setPosition(position);

}

Label::~Label()
{
    //dtor
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_text,states);
}
