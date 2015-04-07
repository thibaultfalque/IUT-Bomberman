#ifndef _INPUT_KEY_HPP_
#define _INPUT_KEY_HPP_
#include "Observateur.hpp"
#include "header.hpp"
#include "General/EventManager.hpp"
#include "General/Ressource.hpp"
class InputKey : public Observateur
{
    protected:

    bool _mouseHover;
    bool _isActive;

    sf::Vector2f _pos;
    sf::Vector2f _size;
    EventManager * _event;
    std::string _eventName;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void onMouseMove(sf::Event & event);
    virtual void onMouseDown(sf::Event & event);
    virtual void onMouseUp(sf::Event & event);
    virtual void onKeyUp(sf::Event & event);

    sf::RectangleShape _fond;
    sf::Text _text;
    virtual void updateGraphic();

    public :

    InputKey(sf::Vector2f pos, sf::Vector2f taille,std::string eventName,EventManager * event);

    virtual void onEvent(sf::Event & event);
    virtual void setPosition(sf::Vector2f pos);
    virtual void setSize(sf::Vector2f taille);
};
#endif // _INPUT_KEY_HPP_
