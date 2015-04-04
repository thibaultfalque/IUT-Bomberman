#include "InputText.hpp"

InputText::InputText(const sf::Vector2f& pos,const sf::Vector2f& taille,const string& str ):_pos(pos),_size(taille),_str(str)
{
    _cursorPosition=_str.size();

    _textArea.setSize(_size);
    _textArea.setPosition(_pos);
    _textArea.setFillColor(sf::Color::Black);
    _textArea.setOutlineColor(sf::Color::White);
    _textArea.setOutlineThickness(2.f);

    _cursor.setFillColor(sf::Color::White);
    _cursor.setSize(sf::Vector2f(1,_size.y));
    _cursor.setPosition(sf::Vector2f(_pos.x+_textArea.getOutlineThickness(),_pos.y));

    _text.setCharacterSize(13);
    _text.setColor(sf::Color::White);
    _text.setFont(Ressource::getFont("default.ttf"));
    _text.setPosition(_pos);
    _text.setString(_str);
}

InputText::~InputText()
{
    //dtor
}
string InputText::getString(){
    return _str;
}
void InputText::onEvent(sf::Event& event){

    switch(event.type){
        case sf::Event::MouseMoved :
            onMouseMove(event);
        break;
        case sf::Event::KeyPressed :
            onKeyPressed(event);
        break;
        case sf::Event::TextEntered :
            onTextEntered(event);
        break;
        case sf::Event::MouseButtonReleased:
            onMouseUp(event);
        break;
        default:
        break;
    }
}
void InputText::onKeyPressed(sf::Event& event){
    if(!_active)
        return;
    switch(event.key.code){
        case sf::Keyboard::Left:
            if(_cursorPosition>0)
                _cursorPosition--;
            if (_cursorPosition<0)
                _cursorPosition=0;
        break;
        case sf::Keyboard::Right:
            _cursorPosition++;
            if(_cursorPosition>_str.size())
                _cursorPosition=_str.size();
        break;
        default:
        break;
    }
    updateCursorPosition();
}
void InputText::onMouseUp(sf::Event& event){
    if(_hover && event.mouseButton.button == sf::Mouse::Left){
        _active=true;
         //sf::Vector2f pos;
         //pos.x=event.mouseButton.x;
         //pos.y=_cursor.getPosition().y;

        //
        //    pos.x=_pos.x+_textArea.getOutlineThickness();
        float relative=event.mouseButton.x-(_pos.x+_textArea.getOutlineThickness());
        if(_str.size()!=0)
            _cursorPosition=relative/(_text.getGlobalBounds().width/_str.size());
        if(_cursorPosition>_str.size())
            _cursorPosition=_str.size();
        //_cursor.setPosition(pos);
    }

    else{
        _active=false;
        _showCursor=false;
    }
    updateCursorPosition();


}
void InputText::onTextEntered(sf::Event& event){
    if(!_active)
        return ;

        if(event.text.unicode>31 && event.text.unicode<127 ){
            if(_cursorPosition!=_str.size())
                _str = _str.substr(0,_cursorPosition)+event.text.unicode+_str.substr(_cursorPosition,_str.size()-1);
            else
                _str+=event.text.unicode;

            _cursorPosition++;
        }
        else if(event.text.unicode == 8 && _cursorPosition>0){
            if(_cursorPosition != _str.size())
                _str = _str.substr(0,_cursorPosition-1)+_str.substr(_cursorPosition,_str.size()-1);
            else
                _str = _str.substr(0,_str.size()-1);
            _cursorPosition --;
        }
        else if(event.text.unicode == 127 && _cursorPosition<_str.size()){
            if(_cursorPosition != 0)
                _str = _str.substr(0,_cursorPosition)+_str.substr(_cursorPosition+1,_str.size()-1);
            else
                _str = _str.substr(1,_str.size()-1);
        }
        _cursorClock.restart();

    _text.setString(_str);
    updateCursorPosition();

}
void InputText::updateCursorPosition(){
    sf::Vector2f cursor;
    cursor.x=_pos.x+_textArea.getOutlineThickness();
    if(_str.size()>0)
        cursor.x+=_cursorPosition*_text.getGlobalBounds().width/_str.size();
    else
        cursor.x+=_cursorPosition*_text.getGlobalBounds().width;
    cursor.y=_pos.y;
    _cursor.setPosition(cursor);
}
void InputText::onMouseMove(sf::Event& event){
    _hover=pointInRect(_pos,_size,sf::Vector2f(event.mouseMove.x,event.mouseMove.y));
}

void InputText::update(){
    if(_active && _cursorClock.getElapsedTime().asSeconds()>0.5){
        _cursorClock.restart();
        _showCursor=!_showCursor;
    }

}

void InputText::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    target.draw(_textArea);
    target.draw(_text);
    if(_showCursor)
        target.draw(_cursor);

}
