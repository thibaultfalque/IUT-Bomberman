#include "BombManager.hpp"


BombManager::BombManager(Map& m,vector<Personnage*> & perso):_map(m),_perso(perso)
{
    _dangerous.resize(_map.getSize().x);
    for(int i=0;i<_dangerous.size();i++){
        for(int j=0;j<_map.getSize().y;j++)
            _dangerous[i].push_back(false);
    }
    _pause=false;

}

BombManager::~BombManager()
{
    for(int i=0;i<_listbombe.size();i++)
        delete _listbombe[i];
}
void BombManager::setPause(bool p ){
    _pause=p;
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
    dangerous.clear();
    for(int i=0;i<_dangerous.size();i++){
        vector<bool> tmp;
        for(int j=0;j<_dangerous.size();j++)
            tmp.push_back(_dangerous[i][j]) ;
        dangerous.push_back(tmp);
    }
    Bomb b(mapPosition);
    b.getListCaseTouch(_map,dangerous);
}
vector<vector<bool>>* BombManager::getTabDangerouseCase(){
    return &_dangerous;
}

bool BombManager::putBomb(Personnage& p,Bomb* b){
    sf::Vector2i mapPosition=_map.getMapPosition(Vector2i(p.getPos().x,p.getPos().y));
    Case* c=_map.getCase(mapPosition.x,mapPosition.y);
    if(dynamic_cast<Mur*>(_map.getCase(mapPosition.x,mapPosition.y))!=nullptr || hasBomb(mapPosition.x,mapPosition.y))
        return false ;
    b->setMapPosition(mapPosition);
    b->setPosition(c->getPosition());
    _listbombe.push_back(b);
    updateDangerous();
    return true;
}


void BombManager::update(sf::Time& tps){
   set<int> deletePerso;
    for(unsigned int i=0;i<_listbombe.size();i++){
        _listbombe[i]->update(tps);
        if(_listbombe[i]->mustExplode()){
            vector<Vector2i> touched=_listbombe[i]->explode(_map);
            for(Vector2i & _case:touched){
                for(int p=0;p<_perso.size();p++)
                    if(_map.getCase(_case.x,_case.y)->getHitBox().intersects(_perso[p]->getHitBox())){
                        deletePerso.insert(p);
                    }

            }
            _listExplosions.push_back(Explosion(_listbombe[i]->getMapPosition()
                                                ,_listbombe[i]->getPower()
                                                ,_listbombe[i]->getPersonnage()->getType()
                                                ,_map));

                _eraseIndex.push_back(i);//*
            }
        }
        for(Explosion & e:_listExplosions)
            e.update(tps);
        for(int i=0;i<_eraseIndex.size() && !_eraseIndex.empty();i++){
            _listbombe.erase(_listbombe.begin()+_eraseIndex[i]);
        }

        list<Explosion>::iterator it=_listExplosions.begin();
        while(it!=_listExplosions.end() && it->getNeedDestroy()){
            _listExplosions.pop_front();
            it=_listExplosions.begin();
        }

        for (set<int>::reverse_iterator it= deletePerso.rbegin(); it != deletePerso.rend(); it++){
            _perso.erase(_perso.begin()+*it);
        }

        if(_eraseIndex.size()>0)
            updateDangerous();
        _eraseIndex.clear();


}
void BombManager::draw(sf::RenderTarget& target,sf::RenderStates states) const {
    for(unsigned int i=0;i<_listbombe.size();i++)
        target.draw(*_listbombe[i],states);
    for(Explosion  e:_listExplosions)
        target.draw(e,states);

}
