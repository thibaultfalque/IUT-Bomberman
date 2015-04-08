#include "BombManager.hpp"

BombManager::BombManager(Map& m):_map(m)
{
    _dangerous.resize(_map.getSize().x);
    for(int i=0;i<_dangerous.size();i++){
        for(int j=0;j<_map.getSize().y;j++)
            _dangerous[i].push_back(false);
    }

}

BombManager::~BombManager()
{
    for(int i=0;i<_listbombe.size();i++)
        delete _listbombe[i];
}

Bomb* BombManager::hasBomb(const unsigned int x,const unsigned int y){
    for(int i=0;i<_listbombe.size();i++){
        if(_listbombe[i]->getMapPosition()==sf::Vector2i(x,y))
            return _listbombe[i];
    }
    return nullptr;
}
void BombManager::updateDangerous(){
    for(int i=0;i<_dangerous.size();i++){
        for(int j=0;j<_dangerous[i].size();j++)
            _dangerous[i][j]=false ;
    }
    for(int i=0;i<_listbombe.size();i++)
        _listbombe[i]->getListCaseTouch(_map,_dangerous);

}

void BombManager::testPutBomb(vector<vector<bool>>& dangerous,sf::Vector2i& mapPosition){
    dangerous.resize(15);
    for(int i=0;i<_dangerous.size();i++){
        for(int j=0;j<_dangerous.size();j++)
            dangerous[i].push_back(_dangerous[i][j]) ;
    }
    Bomb b(mapPosition);
    b.getListCaseTouch(_map,dangerous);
}
vector<vector<bool>>* BombManager::getTabDangerouseCase(){
    return &_dangerous;
}

bool BombManager::putBomb(Personnage& p,Bomb* b){
    sf::FloatRect rect=p.getHitBox();
    sf::Vector2i mapPosition=_map.getMapPosition(sf::Vector2i(rect.left+rect.width/2,rect.top+rect.height/2));
    Case* c=_map.getCase(mapPosition.x,mapPosition.y);
    if(dynamic_cast<Mur*>(_map.getCase(mapPosition.x,mapPosition.y))!=nullptr || hasBomb(mapPosition.x,mapPosition.y))
        return false ;
    b->setMapPosition(mapPosition);
    b->setPosition(c->getPosition());
    _listbombe.push_back(b);
    updateDangerous();
    return true;
}

void BombManager::update(){
   tps=clock.restart();
    for(unsigned int i=0;i<_listbombe.size();i++){
        _listbombe[i]->update(tps);
        if(_listbombe[i]->mustExplode()){
            _listbombe[i]->explode(_map);
            _listExplosions.push_back(Explosion(_listbombe[i]->getMapPosition()
                                                ,_listbombe[i]->getPower()
                                                ,_listbombe[i]->getPersonnage()->getType()
                                                ,_map));

            _eraseIndex.push_back(i);

        }
    }
    for(Explosion & e:_listExplosions)
        e.update();
    for(int i=0;i<_eraseIndex.size() && !_eraseIndex.empty();i++){
        _listbombe.erase(_listbombe.begin()+_eraseIndex[i]);
    }
    if(_eraseIndex.size()>0)
        updateDangerous();
    _eraseIndex.clear();

    list<Explosion>::iterator it=_listExplosions.begin();
    while(it!=_listExplosions.end() && it->getNeedDestroy()){
        _listExplosions.pop_front();
        it=_listExplosions.begin();
    }

}
void BombManager::draw(sf::RenderTarget& target,sf::RenderStates states) const {
    for(unsigned int i=0;i<_listbombe.size();i++)
        target.draw(*_listbombe[i],states);
    for(Explosion  e:_listExplosions)
        target.draw(e,states);
}
