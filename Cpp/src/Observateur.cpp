#include "Observateur.hpp"

Observateur::Observateur()
{
    //ctor
}

Observateur::~Observateur()
{
    //dtor
}
void Observateur::update(){};
void Observateur::onEvent(sf::Event& event){}
void Observateur::draw(sf::RenderTarget& target, sf::RenderStates states) const {}
