#include "Bouton.hpp"

Bouton::Bouton(const string text,Vector2f const& taille,Vector2f const& position,string str):_size(taille),_pos(position)
{
    _rec.setSize(_size);
    _rec.setPosition(_pos);
    _rec.setFillColor(sf::Color::Black);
    _rec.setOutlineColor(sf::Color::White);
    _rec.setOutlineThickness(5.f);
    _text.setString(text);
    _text.setFont(Ressource::getFont("defaut.ttf"));
    _text.setCharacterSize(15);
    _text.setPosition(Vector2f(_pos.x+_size.x/2-_text.getGlobalBounds().width/2,_pos.y+_size.y/2-_text.getGlobalBounds().height/2));

}

Bouton::~Bouton()
{
    //dtor
}
void Bouton::update(){

}
void Bouton::onEvent(sf::Event& event){
    if(event.type==sf::Event::MouseMoved && pointInRect(_pos,_size,Vector2f(event.mouseMove.x,event.mouseMove.y)))
        _rec.setFillColor(sf::Color::White);
    else
        _rec.setFillColor(sf::Color::Black);

    if(event.type==sf::Event::MouseButtonPressed)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pointInRect(_pos,_size,Vector2f(event.mouseButton.x,event.mouseButton.y)))
            ScreenManager::goToScreen(_action);

}
void Bouton::setAction(string str){
    _action=str;
}
void Bouton::draw(sf::RenderTarget& target,sf::RenderStates states) const {
    target.draw(_rec);
    target.draw(_text);
}
