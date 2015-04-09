#include "Checkbox.hpp"

Checkbox::Checkbox(Observable* obs,sf::Vector2f posIn,sf::Vector2f posOut, sf::Vector2f sizeIn, sf::Vector2f sizeOut,bool valDepart):_posRecIn(posIn),_posRecOut(posOut),_sizeRecIn(sizeIn),_sizeRecOut(sizeOut)
{
    _recOut.setPosition(_posRecOut);
    _recOut.setSize(_sizeRecOut);
    _recOut.setFillColor(sf::Color::Black);
    _recOut.setOutlineColor(sf::Color::White);
    _recOut.setOutlineThickness(2.f);

    _recIn.setPosition(_posRecIn);
    _recIn.setSize(_sizeRecIn);
    _recIn.setFillColor(sf::Color::Red);

    _click=valDepart;
    _hover=valDepart;

    _obs=obs;
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
    if(event.type==sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        onMouseClick(event);
}
void Checkbox::onMouseClick(sf::Event& event){
  if(_hover){
    _click=!_click;
    _obs->notifyChangeCheckbox(_click);
  }
}
void Checkbox::onMouseHover(sf::Event& event){
    _hover=pointInRect(_posRecOut,_sizeRecOut,sf::Vector2f(event.mouseMove.x,event.mouseMove.y));

}
void Checkbox::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_recOut);
    if(_click)
        target.draw(_recIn);
}
