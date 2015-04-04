#include "IA.hpp"

IA::IA(const sf::Vector2f& position,const string& str,Map & __map,BombManager & bm):Personnage(position,str,__map,bm)
{
    sf::FloatRect rect=getHitBox();
    goal=_map.getMapPosition(sf::Vector2i(rect.left+rect.width/4,rect.top+rect.height/4));
    //goal=_map.getMapPosition(sf::Vector2i(pos.x,pos.y));

     _dangerous=_bombeManager.getTabDangerouseCase();
     //_indiceGoal=0;
}

IA::~IA()
{
    //dtor
}
void IA::update(){

    sf::FloatRect rect=getHitBox();
    sf::Vector2i mapPosition=_map.getMapPosition(sf::Vector2i(rect.left+rect.width/2,rect.top+rect.height/2));
    cout<<"MAP POSITION "<<mapPosition.x<<" "<<mapPosition.y<<endl;
    cout<<"goal "<<goal.x<<" "<<goal.y<<endl;
    if(goal==mapPosition){
        if(!chemin.empty()){
            goal=chemin.top();
            chemin.pop();
            if(!_map.canWalk(goal.x,goal.y))
                choiceNewGoal();
        }
        else{
            choiceNewGoal();
        }
    }
    vitesse = Vector2f(0,0);
    float pixelParSecondes = 70;

    /*if(goal.x<mapPosition.x)
        vitesse.x -= pixelParSecondes;
    if(goal.x>mapPosition.x)
        vitesse.x += pixelParSecondes;
    if(goal.y<mapPosition.y)
        vitesse.y -= pixelParSecondes;
    if(goal.y>mapPosition.y)
        vitesse.y += pixelParSecondes;*/

    sf::Vector2f centerPositionGoal=sf::Vector2f(_map.getCase(goal.x,goal.y)->getPosition().x+LARGEUR/4,
    _map.getCase(goal.x,goal.y)->getPosition().y+HAUTEUR/4);
    if(centerPositionGoal.x<pos.x)
        vitesse.x -= pixelParSecondes;
    if(centerPositionGoal.x>pos.x)
        vitesse.x += pixelParSecondes;
    if(centerPositionGoal.y<pos.y)
        vitesse.y -= pixelParSecondes;
    if(centerPositionGoal.y>pos.y)
        vitesse.y += pixelParSecondes;

    if(vitesse.x*vitesse.y!=0){
        vitesse = (vitesse/sqrt(vitesse.x*vitesse.x + vitesse.y*vitesse.y))*pixelParSecondes;
    }

    moveTo(pos +vitesse*deltaUpdate.getElapsedTime().asSeconds());

    //GRAPHIC UPDATE

    for(int y=0;y<4;y++)
    for(int x=0;x<9;x++)
        _sprites[y][x].setPosition(pos);

    if(timerPas.getElapsedTime().asSeconds()>=0.06){
        timerPas.restart();
        etapePas = (++etapePas)%9;
    }
    if(vitesse.x==0 && vitesse.y == 0){
        etapePas = 0;
    }
    else if(abs(vitesse.x)>abs(vitesse.y)){
        if(vitesse.x<0)
            direction = 3;
        else
            direction = 1;
    }else{
        if(vitesse.y<0)
            direction = 2;
        else
            direction = 0;
    }
    deltaUpdate.restart();
}
void IA::choiceNewGoal(){
    sf::FloatRect rect=getHitBox();
    sf::Vector2i mapPosition=_map.getMapPosition(sf::Vector2i(rect.left+rect.width/2,rect.top+rect.height/2));

    Graph g(_map,mapPosition);
    if((*_dangerous)[mapPosition.x][mapPosition.y]){
        defenseAction(g);

    }
    else{
        offenseAction(g);
    }
}
void IA::offenseAction(Graph& g){
    short n =rand_int(0,3);
    int dir_x[] = {-1,0,1,0};
    int dir_y[] = {0,-1,0,1};
    sf::FloatRect rect=getHitBox();
    sf::Vector2i mapPosition=_map.getMapPosition(sf::Vector2i(rect.left+rect.width/2,rect.top+rect.height/2));
    sf::Vector2i newMapPosition=sf::Vector2i(mapPosition.x+dir_x[n],mapPosition.y+dir_y[n]);
    if(newMapPosition.x<0 || newMapPosition.x>=15 ||newMapPosition.y<0 || newMapPosition.y>=15 || !_map.canWalk(newMapPosition.x,newMapPosition.y))
      return;

    int put=rand_int(0,7);
    if(put==0){
        putBomb();
    }
    goal=newMapPosition;
}
void IA::defenseAction(Graph& g){
    sf::FloatRect rect=getHitBox();
    sf::Vector2i mapPosition=_map.getMapPosition(sf::Vector2i(rect.left+rect.width/2,rect.top+rect.height/2));
    sf::Vector2i tmp=g.breadFirstSearch(mapPosition,*_dangerous,_map);

    g.getPath(mapPosition,tmp,chemin);

    if(!chemin.empty()){
        goal=chemin.top();
        chemin.pop();
    }
}


void IA::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    Personnage::draw(target,states);
}

void IA::putBomb(){
    sf::Vector2i p=_map.getMapPosition(sf::Vector2i((int)pos.x,(int)pos.y));
        if(nbBombe!=0 ){
            bool succedPut=_bombeManager.putBomb(*this,new Bomb("bombeP2.png",pos,degatsBombes));
            if(succedPut){
                removeBombe();
                choiceNewGoal();
            }
        }

}
