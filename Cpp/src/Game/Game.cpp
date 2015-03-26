#include "Game.hpp"


Game::Game(sf::Vector2i* s):_map("res/map/map2.lvl",*s),_bombManager(_map),_background("backgroundGame.png"),_mapDangerousZone(_map.getSize().x),p_test(sf::Vector2f(_map.getPosition().x,_map.getPosition().y),"bombermanspritesP0.png",_map,_eventManager,_bombManager)
{
    _window_size=s;


}

Game::~Game()
{
    //dtor
}

void Game::onEvent(sf::Event & event){
    p_test.onEvent(event);
}

void Game::update(){
    _bombManager.update();
    p_test.update();

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_background,states);
    target.draw(_map,states);
    target.draw(p_test,states);
//    _bombManager.draw(target,states);
}
