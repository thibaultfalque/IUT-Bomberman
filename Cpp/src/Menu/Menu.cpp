#include "Menu.hpp"

Menu::Menu(sf::Vector2i* s):
_background("backgroundMenu.png")
{
    _window_size=s;
}

Menu::~Menu()
{
    //dtor
}
void Menu::onEvent(sf::Event& event){
    for(unsigned int i=0;i<obs.size();i++)
        obs[i]->onEvent(event);
}
void Menu::update(){
    updateObs();
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_background);
    for(unsigned int i=0;i<obs.size();i++)
       target.draw(*obs[i],states);
}


void Menu::updateObs(){
    for(unsigned int i=0;i<obs.size();i++)
        obs[i]->update();
}
