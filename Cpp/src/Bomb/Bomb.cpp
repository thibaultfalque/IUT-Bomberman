#include "Bomb/Bomb.hpp"
Bomb::Bomb(string tex,Vector2f const& position, int puissance)
{
    sprite=Ressource::getSprite(tex,IntRect(0,0,0,0));
    sprite.setPosition(position);
    power=puissance;
    countdown();
}

void Bomb::countdown(){
    sf::Clock clock;
    sf::Time time;
    while(true){
        time=clock.getElapsedTime();
        if(time.asMilliseconds()>3000){
            explode();
        }
    }
}

void Bomb::explode(){


}

void Bomb::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(sprite,states);
}

Bomb::~Bomb()
{
    //dtor
}
