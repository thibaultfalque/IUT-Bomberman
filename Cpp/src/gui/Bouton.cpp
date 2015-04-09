#include "Bouton.hpp"

Bouton::Bouton(const string text,Vector2f const& taille,Vector2f const& position,string str):_size(taille),_pos(position),_action(str)
{

    _rec.setSize(_size);
    _rec.setPosition(_pos);
    _rec.setFillColor(sf::Color(0,0,0,0));
    _rec.setOutlineColor(sf::Color::White);
    _rec.setOutlineThickness(2.f);
    _text.setString(text);
    _text.setFont(Ressource::getFont("defaut.ttf"));
    _text.setCharacterSize(15);
    _text.setPosition(Vector2f(_pos.x+_size.x/2-_text.getGlobalBounds().width/2,_pos.y+_size.y/2-_text.getGlobalBounds().height/2));
    _action=str;
    _hover=false;
}

Bouton::~Bouton()
{
    //dtor
}
void Bouton::update(){

}
bool Bouton::getHover(){
    return _hover;
}
void Bouton::onMouseClick(sf::Event& event){
    if (pointInRect(_pos,_size,Vector2f(event.mouseButton.x,event.mouseButton.y))){
        ScreenManager::goToScreen(_action);
    }
}

void Bouton::onMouseHover(sf::Event& event){
    if(pointInRect(_pos,_size,Vector2f(event.mouseMove.x,event.mouseMove.y))){
        _rec.setFillColor(sf::Color(0,0,0,128));
        _hover=true;
    }
    else{
        _rec.setFillColor(sf::Color(0,0,0,0));
        _hover=false;
    }
}

void Bouton::onEvent(sf::Event& event){
    if( event.type==sf::Event::MouseMoved)
        onMouseHover(event);

    if(event.type==sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        onMouseClick(event);

}
void Bouton::setAction(string str){
    _action=str;
}
void Bouton::draw(sf::RenderTarget& target,sf::RenderStates states) const {
    target.draw(_rec);
    target.draw(_text);
}
sf::Vector2f Bouton::getPosition(){
    return _pos;
}
sf::Vector2f Bouton::getSize(){
    return _size;
}
