#include "MenuPause.hpp"

MenuPause::MenuPause(sf::Vector2i* s):Menu(s)
{
    sf::Vector2f boutonSize(_window_size->x*0.2,_window_size->y*0.1);
    sf::Vector2f positionBouton(_window_size->x/2-boutonSize.x/2,_window_size->y/2-boutonSize.y-boutonSize.y/2);
    addObs("Retour au Jeu",new Bouton("Retour Au Jeu",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*0),"Game"));
    addObs("Options",new Bouton("Options",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*1),"Options"));
    addObs("Options Touches",new Bouton("Options Touches",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*2),"OptionsTouches"));
    addObs("Quitter",new Bouton("Quitter",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*3),"Menu"));
}

MenuPause::~MenuPause()
{
    //dtor
}
