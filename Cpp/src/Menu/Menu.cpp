#include "Menu.hpp"

Menu::Menu(sf::Vector2i* s):
_background("backgroundMenu.png")
{
    _window_size=s;
}

Menu::~Menu()
{
   delete _window_size;
}
void Menu::onEvent(sf::Event& event){
    for(map<string,Observateur*>::iterator it=_gui.begin();it!=_gui.end();it++){

        it->second->onEvent(event);
    }
}
void Menu::update(sf::Time& tps){
    updateObs(tps);
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_background);
    for(map<string,Observateur*>::const_iterator it=_gui.begin();it!=_gui.end();it++)
       target.draw(*it->second,states);
}


void Menu::updateObs(sf::Time& tps){
    for(map<string,Observateur*>::iterator it=_gui.begin();it!=_gui.end();it++)
        it->second->update();
}
void Menu::addObs(string str,Observateur* obs){
    _gui[str]=obs;
}
