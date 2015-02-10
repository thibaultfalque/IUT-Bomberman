#include "Bouton.hpp"

Bouton::Bouton(const string text,Vector2f const& taille,Vector2f const& position):_size(taille),_pos(position)
{
    _rec.setSize(_size);
    _rec.setPosition(_pos);
    _rec.setFillColor(sf::Color::Black);
    _rec.setOutlineColor(sf::Color::White);
    _rec.setOutlineThickness(10.f);
    _text.setString(text);
    _text.setFont(Ressource::getFont("defaut.ttf"));

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
}
void Bouton::draw(sf::RenderTarget& target,sf::RenderStates states) const {
    target.draw(_rec);
    cout<<"je draw des boutons"<<endl;
}
