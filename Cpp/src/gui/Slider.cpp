#include "Slider.hpp"

Slider::Slider(Observable* obs,const float& valMin, const float& valMax,const float& val,const sf::Vector2f& taille, const sf::Vector2f& pos):_valMin(valMin),_valMax(valMax),_currentValue(val),_size(taille),_pos(pos)
{
    _bar.setSize(_size);
    _bar.setPosition(_pos);
    _bar.setFillColor(sf::Color(0,0,0,0));
    _bar.setOutlineThickness(3.f);
    _bar.setOutlineColor(sf::Color::White);

    _cursor.setFillColor(sf::Color::Black);
    _cursor.setSize(sf::Vector2f(15,_size.y+20));
    _cursor.setPosition(Vector2f(_pos.x+(_size.x*_currentValue)/_valMax,_pos.y-_size.y/2*2));

    _obs=obs;
}

Slider::~Slider()
{
    //dtor
}
void Slider::onEvent(Event& event){
    if(event.type==sf::Event::MouseMoved)
        onMouseHover(event);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        onMouseClick(event);
}
/*
float Slider::getValeur(){
    return (int)(circle.getPosition().x/(line.getGlobalBounds().width/100)-100);
}*/

void Slider::onMouseClick(Event& event){
     if(_isHover){
        _cursor.setPosition(_positionSouris.x,_cursor.getPosition().y);
        if(_cursor.getPosition().x<_pos.x)
            _cursor.setPosition(_pos.x,_cursor.getPosition().y);
        else if(_cursor.getPosition().x>_pos.x+_size.x-_cursor.getSize().x)
            _cursor.setPosition(_pos.x+_size.x-_cursor.getSize().x,_cursor.getPosition().y);
    }

}
void Slider::onMouseHover(Event& event){

    _positionSouris.x=event.mouseMove.x;
    _positionSouris.y=event.mouseMove.y;
    _isHover=pointInRect(_cursor.getPosition(),_cursor.getSize(),_positionSouris)
    ||pointInRect(_pos,_size,_positionSouris);

}
void Slider::draw(sf::RenderTarget& target,sf::RenderStates states) const {
    target.draw(_bar,states);
    target.draw(_cursor,states);
}
