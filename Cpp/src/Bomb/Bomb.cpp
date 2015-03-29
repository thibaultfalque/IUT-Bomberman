#include "Bomb/Bomb.hpp"
Bomb::Bomb(string tex,Vector2f const& position, int puissance):textureName(tex)
{
    sprite=Ressource::getSprite(textureName,IntRect(0,0,LARGEUR,HAUTEUR));
    sprite.setPosition(position);
    power=puissance;
    stratBomb=new StratBombSimple();
    _explosion=false;

}

void Bomb::update(sf::Time tps){
    tempTotal+=tps.asMilliseconds();
    if(_explosion)
        return;
    if(tempTotal>2250 && !_explosion){
        _explosion=true;
        tempTotal=0;
    }

    if(tempTotal>2000 && !_explosion){
        sprite=Ressource::getSprite(textureName,IntRect(LARGEUR*2,0,LARGEUR,HAUTEUR));
        sprite.setPosition(position);

    }
    else if(tempTotal>1000 && !_explosion){
        sprite=Ressource::getSprite(textureName,IntRect(LARGEUR,0,LARGEUR,HAUTEUR));
        sprite.setPosition(position);
    }


}
bool Bomb::mustExplode(){
    return _explosion;
}
void Bomb::getListCaseTouch(Map& m,vector<vector<bool>>& tab){
    stratBomb->getCaseTouch(m,tab,*this);
}
void Bomb::explode(Map& m){
    stratBomb->explode(m,*this);
    _explosion=false;
}
void Bomb::setMapPosition(const sf::Vector2i& mapPosition){
    _mapPosition=mapPosition;
}
sf::Vector2i& Bomb::getMapPosition(){
    return _mapPosition;
}
void Bomb::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(sprite,states);
}
void Bomb::setPosition(const sf::Vector2f& pos){
    position=pos;
    sprite.setPosition(pos);
}
int Bomb::getPower(){
    return power;
}
Bomb::~Bomb()
{
    //dtor
}
