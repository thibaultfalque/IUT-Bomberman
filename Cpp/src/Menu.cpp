#include "Menu.hpp"

Menu::Menu(sf::Vector2i* s):Screen(),Observable()
{
    _window_size=s;
    sf::Vector2f boutonSize(_window_size->x*0.1,_window_size->y*0.05);
    Bouton b1("Mode Campagne",boutonSize,Vector2f(0.f,0.f));
    addObs(b1);
    /*addObs(Bouton("Mode Multijoueur",boutonSize));
    addObs(Bouton("Options",boutonSize));
    addObs(Bouton("Options Touches",boutonSize));*/
}

Menu::~Menu()
{
    //dtor
}
void Menu::onEvent(sf::Event& event){
    for(unsigned int i=0;i<obs.size();i++)
        obs[i].onEvent(event);
}
void Menu::update(){
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(unsigned int i=0;i<obs.size();i++)
       target.draw(obs[i],states);
}


void Menu::updateObs(){
    for(unsigned int i=0;i<obs.size();i++)
        obs[i].update();
}
