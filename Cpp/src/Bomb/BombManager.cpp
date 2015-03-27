#include "BombManager.hpp"

BombManager::BombManager(Map& m):_map(m)
{


}

BombManager::~BombManager()
{


}

bool BombManager::hasBomb(const unsigned int x,const unsigned int y){
    for(int i=0;i<_listbombe.size();i++){
        if(_listbombe[i]->getMapPosition()==sf::Vector2i(x,y))
            return true;
    }
    return false;
}
void BombManager::putBomb(const sf::Vector2i& mapPosition,const sf::Vector2f& screenPosition,Bomb* b){
    b->setMapPosition(mapPosition);
    _listbombe.push_back(b);

    _listbombe.back()->setMapPosition(mapPosition);
    //_listbombe.back()->setPosition(sf::Vector2f(_map.getCase(mapPosition.x,mapPosition.y)->getPosition().x+LARGEUR/4,_map.getCase(mapPosition.x,mapPosition.y)->getPosition().y+HAUTEUR/4));
    _listbombe.back()->setPosition(sf::Vector2f(screenPosition.x,screenPosition.y));
}

void BombManager::update(){
   tps=clock.restart();
    for(unsigned int i=0;i<_listbombe.size();i++){
        _listbombe[i]->update(tps);
        if(_listbombe[i]->mustExplode()){
            _listbombe[i]->explode(_map);
            _listbombe.erase(_listbombe.begin()+i);
        }

    }

}
void BombManager::draw(sf::RenderTarget& target,sf::RenderStates states) const {
    for(unsigned int i=0;i<_listbombe.size();i++)
        target.draw(*_listbombe[i],states);
}
