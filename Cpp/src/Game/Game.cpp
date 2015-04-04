#include "Game.hpp"


Game::Game(sf::Vector2i* s):_map("res/map/map2.lvl",*s),
_bombManager(_map),_background("backgroundGame.png"),
_mapDangerousZone(_map.getSize().x)

{
    _window_size=s;
    p_test=new Humain(sf::Vector2f(_map.getPosition().x,_map.getPosition().y),"bombermanspritesP0.png",_map,_eventManager,_bombManager);
    vector<sf::Vector2i> pos=_map.getPosDepartPerso();
    for(int i=0;i<pos.size();i++){
        sf::Vector2f position=_map.getCase(pos[i].x,pos[i].y)->getPosition();
        _ia.push_back(new IA(sf::Vector2f(position.x+LARGEUR/4,position.y+HAUTEUR/4),"bombermanspritesP"+to_string(i+1)+".png",_map,_bombManager));
    }

}

Game::~Game()
{
    //dtor
}

void Game::onEvent(sf::Event & event){
    p_test->onEvent(event);
}

void Game::update(){
    _bombManager.update();
    p_test->update();
    for(int i=0;i<_ia.size();i++){
        _ia[i]->update();
    }


}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_background,states);
    target.draw(_map,states);
    _bombManager.draw(target,states);
    for(int i=0;i<_ia.size();i++)
        target.draw(*_ia[i],states);
    target.draw(*p_test,states);
}
