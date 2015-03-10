#include "Game.hpp"

Game::Game(sf::Vector2i* s):_map("res/map/map1.lvl")
{
    _window_size=s;
}

Game::~Game()
{
    //dtor
}
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_map,states);
}
