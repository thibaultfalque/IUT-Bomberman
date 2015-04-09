#include "MenuOptionTouch.hpp"

MenuOptionTouch::MenuOptionTouch(sf::Vector2i* s,EventManager& event):Menu(s),_event(event)
{
    sf::Vector2f boutonSize(_window_size->x*0.4,_window_size->y*0.06);
    sf::Vector2f boutonRetourSize(_window_size->x*0.2,_window_size->y*0.06);
    sf::Vector2f positionBouton(_window_size->x/2-boutonSize.x/2,_window_size->y/3-boutonSize.y-boutonSize.y/4);
    sf::Vector2f positionRetour(_window_size->x*0.1,_window_size->y*0.1);
    addObs("Retour",new Bouton("Retour",boutonRetourSize,positionRetour,"Menu"));

    int i=0;
    for(EventConf::iterator it=_event.getListKey().begin();it!=_event.getListKey().end();++it){
        addObs(it->first,new InputKey(Vector2f(positionBouton.x,positionBouton.y+0.08*_window_size->y*i),boutonSize,it->first,&_event));
        i++;
    }

}

MenuOptionTouch::~MenuOptionTouch()
{

}
