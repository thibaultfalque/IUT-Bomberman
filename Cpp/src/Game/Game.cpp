#include "Game.hpp"

Game::Game(sf::Vector2i* s):_map("res/map/map2.lvl"),_background("backgroundGame.png"),_mapbombe(_map.getSize().x),_mapDangerousZone(_map.getSize().x)
{
    _window_size=s;

}

Game::~Game()
{
    //dtor
}
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_background,states);
    target.draw(_map,states);
}
