#include "Checkbox.hpp"

Checkbox::Checkbox()
{
    //ctor
}

Checkbox::~Checkbox()
{
    //dtor
}
bool Checkbox::isClick(){
    return _click;
}
void Checkbox::onEvent(sf::Event& event){
    if(event.type==sf::Event::MouseMoved)
        onMouseHover(event);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        onMouseClick(event);
}
void Checkbox::onMouseClick(sf::Event& event){
}
void Checkbox::onMouseHover(sf::Event& event){
}
