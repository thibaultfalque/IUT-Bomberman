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

void BombManager::getTabDangerouseCase(vector<vector<bool>>& dangerous){
    dangerous.resize(_map.getSize().x);
    for(int i=0;i<dangerous.size();i++){
        for(int j=0;j<_map.getSize().y;j++)
            dangerous[i].push_back(false);
    }
    for(int i=0;i<_listbombe.size();i++)
        _listbombe[i]->getListCaseTouch(_map,dangerous);

}

bool BombManager::putBomb(Personnage& p,Bomb* b){
    sf::FloatRect rect=p.getHitBox();
    sf::Vector2i mapPosition=_map.getMapPosition(sf::Vector2i(rect.left+rect.width/2,rect.top+rect.height/2));
    Case* c=_map.getCase(mapPosition.x,mapPosition.y);
    if(dynamic_cast<Mur*>(_map.getCase(mapPosition.x,mapPosition.y))!=nullptr)
        return false ;
    b->setMapPosition(mapPosition);
    _listbombe.push_back(b);
    _listbombe.back()->setPosition(c->getPosition());
    return true;
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
