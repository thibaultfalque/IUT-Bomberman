#include "Game.hpp"

Game::Game(sf::Vector2i* s):_map("res/map/map1.lvl"),p_test(sf::Vector2f(10,10))
{
    _window_size=s;
}

Game::~Game()
{
    //dtor
}

void Game::onEvent(sf::Event & event){

}

void Game::update(){
    p_test.update();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_map,states);
    target.draw(p_test,states);
}
