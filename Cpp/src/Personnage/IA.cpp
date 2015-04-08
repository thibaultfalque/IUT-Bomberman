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
    //Position logique personnage
    sf::Vector2i mapPosition=_map.getMapPosition(Vector2i(pos.x,pos.y));

    //Position graphique goal
    sf::Vector2i centerPositionGoal=_map.getScreenPosition(goal);
    centerPositionGoal.x += LARGEUR/2;
    centerPositionGoal.y += HAUTEUR/2;

    float pixelParSecondes = 70;
    if(vitesse == Vector2f(0,0)){
        vitesse =  Vector2f(centerPositionGoal.x,centerPositionGoal.y) - pos;
        if(vitesse.x*vitesse.y!=0){
            vitesse = (vitesse/sqrt(vitesse.x*vitesse.x + vitesse.y*vitesse.y))*pixelParSecondes;
        }else{
            if(vitesse.x!=0)
                vitesse.x = (vitesse.x<0?-pixelParSecondes:pixelParSecondes);
            else if(vitesse.y!=0)
                vitesse.y = (vitesse.y<0?-pixelParSecondes:pixelParSecondes);
        }
    }


    Vector2f memPos = pos;
    moveTo(pos +vitesse*deltaUpdate.getElapsedTime().asSeconds());

    if(pos==memPos)
        choiceNewGoal();

    if((centerPositionGoal.x-pos.x)*(centerPositionGoal.x-pos.x)+(centerPositionGoal.y-pos.y)*(centerPositionGoal.y-pos.y)
      >(centerPositionGoal.x-memPos.x)*(centerPositionGoal.x-memPos.x)+(centerPositionGoal.y-memPos.y)*(centerPositionGoal.y-memPos.y)){
            if(!chemin.empty()){
                goal=chemin.top();
                chemin.pop();
            }else{
                choiceNewGoal();
            }
            //pos=Vector2f(centerPositionGoal.x,centerPositionGoal.y);
            vitesse=Vector2f(0,0);
      }

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
    sf::Vector2i mapPosition=_map.getMapPosition(Vector2i(pos.x,pos.y));
    sf::Vector2i newMapPosition=sf::Vector2i(mapPosition.x+dir_x[n],mapPosition.y+dir_y[n]);
    if(!_map.canWalk(newMapPosition.x,newMapPosition.y)
       || (*_dangerous)[newMapPosition.x][newMapPosition.y])
      return;


    int put=rand_int(0,7);
    if(put==0){
        tryPutBomb(g);
    }
    goal=newMapPosition;
}
void IA::defenseAction(Graph& g){
    sf::Vector2i mapPosition=_map.getMapPosition(sf::Vector2i(pos.x,pos.y));
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
    sf::Vector2i p=_map.getMapPosition(sf::Vector2i(pos.x,pos.y));
    _bombeManager.testPutBomb(dangerous,p);
    sf::Vector2i tmp=g.breadFirstSearch(p,dangerous,_map);
    stack<Vector2i> chm;
    g.getPath(p,tmp,chm);
    if(chm.size()>5 || chm.empty())
        return false ;
    else{
        putBomb();
        return true;
    }
}

void IA::onEvent(sf::Event& event){}
