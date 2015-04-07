#include "IA.hpp"

IA::IA(const sf::Vector2f& position,int numPersonnage,Map & __map,BombManager & bm):Personnage(position,numPersonnage,__map,bm)
{
    sf::FloatRect rect=getHitBox();
    goal=_map.getMapPosition(sf::Vector2i(rect.left+rect.width/2,rect.top+rect.height/2));
     _dangerous=_bombeManager.getTabDangerouseCase();

}

IA::~IA()
{
    //dtor
}
void IA::update(){

    sf::FloatRect rect=getHitBox();
    sf::Vector2i mapPosition=_map.getMapPosition(sf::Vector2i(rect.left+rect.width/2,rect.top+rect.height/2));

    sf::Vector2f centerPositionGoal=sf::Vector2f(_map.getCase(goal.x,goal.y)->getPosition().x+LARGEUR/4,
    _map.getCase(goal.x,goal.y)->getPosition().y+HAUTEUR/4);

    sf::Vector2f pos2=sf::Vector2f(rect.left+rect.width/2,rect.top+rect.height/2);

    if(mapPosition==goal){
        pos=centerPositionGoal;
        if(!chemin.empty()){
            goal=chemin.top();
            chemin.pop();
        }
        else{
            choiceNewGoal();
        }
    }
    vitesse = Vector2f(0,0);
    float pixelParSecondes = 38;


    if(centerPositionGoal.x<pos2.x && mapPosition.y==goal.y)
            vitesse.x -= pixelParSecondes;
    else if(centerPositionGoal.x>pos2.x && mapPosition.y==goal.y)
            vitesse.x += pixelParSecondes;
    else if(centerPositionGoal.y<pos2.y && mapPosition.x==goal.x)
            vitesse.y -= pixelParSecondes;
    else if(centerPositionGoal.y>pos2.y && mapPosition.x==goal.x)
            vitesse.y += pixelParSecondes;
    else
        choiceNewGoal();
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
        tryPutBomb(g);
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
            bool succedPut=_bombeManager.putBomb(*this,new Bomb(*this,degatsBombes));
            if(succedPut){
                removeBombe();
                choiceNewGoal();
            }
        }

}
bool IA::tryPutBomb(Graph& g){
    vector<vector<bool>> dangerous;
    sf::Vector2i p=_map.getMapPosition(sf::Vector2i((int)pos.x,(int)pos.y));
    _bombeManager.testPutBomb(dangerous,p);
    sf::Vector2i tmp=g.breadFirstSearch(p,dangerous,_map);

    if(tmp==sf::Vector2i(-1,-1))
        return false ;
    else{
        putBomb();
        return true;
    }
}

void IA::onEvent(sf::Event& event){}
