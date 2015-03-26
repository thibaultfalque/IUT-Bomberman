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
    Sol* ca = dynamic_cast<Sol*>(_map.getCase(mapPosition.x,mapPosition.y));
    if(ca!=nullptr){
        ca->setBomb(b);
    }
    b->setMapPosition(mapPosition);
    _listbombe.push_back(b);

 //   _mapbombe[mapPosition.x][mapPosition.y]->setMapPosition(mapPosition);
//    _mapbombe[mapPosition.x][mapPosition.y]->setPosition(sf::Vector2f(_map.getCase(mapPosition.x,mapPosition.y)->getPosition().x+LARGEUR/4,_map.getCase(mapPosition.x,mapPosition.y)->getPosition().y+HAUTEUR/4));
}

void BombManager::update(){
   tps=clock.restart();
    for(unsigned int i=0;i<_listbombe.size();i++){
        _listbombe[i]->update(tps);
        if(_listbombe[i]->mustExplode())
            _listbombe[i]->explode(_map);
    }

}
/*void BombManager::draw(sf::RenderTarget& target,sf::RenderStates states) const {
    for(unsigned int i=0;i<_listbombe.size();i++)
        target.draw(*_listbombe[i],states);
}*/
