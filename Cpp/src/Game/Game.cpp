#include "Game.hpp"


Game::Game(sf::Vector2i* s):_map("res/map/map2.lvl",*s),
_bombManager(_map),_background("backgroundGame.png"),
_mapDangerousZone(_map.getSize().x)

{
    _window_size=s;
    vector<sf::Vector2i> pos=_map.getPosDepartPerso();
    _perso.push_back(new Humain(sf::Vector2f(_map.getPosition().x,_map.getPosition().y),0,_map,_eventManager,_bombManager));
    for(int i=0;i<pos.size();i++){
        sf::Vector2f position=_map.getCase(pos[i].x,pos[i].y)->getPosition();
        _perso.push_back(new IA(sf::Vector2f(position.x+LARGEUR/4,position.y+HAUTEUR/4),i+1,_map,_bombManager));
    }

}

Game::~Game()
{
    //dtor
}

void Game::onEvent(sf::Event & event){
    for(int i=0;i<_perso.size();i++){
        _perso[i]->onEvent(event);
    }
}

void Game::update(){
    _bombManager.update();
    for(int i=0;i<_perso.size();i++){
        _perso[i]->update();
    }


}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_background,states);
    target.draw(_map,states);
    _bombManager.draw(target,states);
    for(int i=0;i<_perso.size();i++)
        target.draw(*_perso[i],states);
}
