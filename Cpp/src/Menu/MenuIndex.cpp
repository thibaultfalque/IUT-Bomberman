#include "MenuIndex.hpp"

MenuIndex::MenuIndex(sf::Vector2i* s):Menu(s)
{
    sf::Vector2f boutonSize(_window_size->x*0.2,_window_size->y*0.1);
    sf::Vector2f positionBouton(_window_size->x/2-boutonSize.x/2,_window_size->y/2-boutonSize.y-boutonSize.y/2);
    //création des boutons

    addObs(new Bouton("Mode Campagne",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*0),"Game"));
    addObs(new Bouton("Mode Multijoueur",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*1),"Multi"));
    addObs(new Bouton("Options",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*2),"Options"));
    addObs(new Bouton("Options Touches",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*3),"OptionsTouches"));
    addObs(new Bouton("Editeur",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*4),"Editeur"));
    //addObs(new Slider(0,100,0,Vector2f(200,10),Vector2f(10,20)));
    //addObs(new Checkbox(sf::Vector2f(50,50),sf::Vector2f(45,45),sf::Vector2f(10,10),sf::Vector2f(20,20)));
    //addObs(new InputText(sf::Vector2f(100,100),sf::Vector2f(200,20),""));
}

MenuIndex::~MenuIndex()
{
    //dtor
}


