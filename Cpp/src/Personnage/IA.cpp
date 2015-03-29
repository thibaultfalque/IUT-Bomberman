#include "IA.hpp"

IA::IA(const sf::Vector2f& position,const string& str,Map & __map,BombManager & bm):Personnage(position,str,__map,bm)
{
    goal=_map.getMapPosition(sf::Vector2i(pos.x,pos.y));
    _bomb.push_back(new Bomb("bombeP2.png",sf::Vector2f(0,0),degatsBombes));
    _bomb.push_back(new Bomb("bombeP2.png",sf::Vector2f(0,0),degatsBombes));
    _bomb.push_back(new Bomb("bombeP2.png",sf::Vector2f(0,0),degatsBombes));
    _bomb.push_back(new Bomb("bombeP2.png",sf::Vector2f(0,0),degatsBombes));
    _bomb.push_back(new Bomb("bombeP2.png",sf::Vector2f(0,0),degatsBombes));
    _bomb.push_back(new Bomb("bombeP2.png",sf::Vector2f(0,0),degatsBombes));

}

IA::~IA()
{
    //dtor
}
void IA::update(){
    sf::Vector2i mapPosition=_map.getMapPosition(Vector2i(pos.x,pos.y));
    if(goal==mapPosition){
        cout<<"choice a new goal"<<endl;
        choiceNewGoal();
    }

    vitesse = Vector2f(0,0);
    float pixelParSecondes = 70;
    if(goal.x<mapPosition.x)
        vitesse.x -= pixelParSecondes;
    if(goal.x>mapPosition.x)
        vitesse.x += pixelParSecondes;
    if(goal.y<mapPosition.y)
        vitesse.y -= pixelParSecondes;
    if(goal.y>mapPosition.y)
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
    vector<vector<bool>> dangerous;
    sf::Vector2i mapPosition=_map.getMapPosition(Vector2i(pos.x,pos.y));
    _bombeManager.getTabDangerouseCase(dangerous);

    Graph g(_map,mapPosition);
    if(dangerous[mapPosition.x][mapPosition.y]){
        cout<<"defense action"<<endl;
        defenseAction(g,dangerous);

    }
    else{
        offenseAction();
    }
}
void IA::offenseAction(){
    //srand(time(NULL));
    short n =rand_int(0,3);
    int dir_x[] = {-1,0,1,0};
    int dir_y[] = {0,-1,0,1};
    sf::Vector2i mapPosition=_map.getMapPosition(Vector2i(pos.x,pos.y));
    sf::Vector2i newMapPosition=sf::Vector2i(mapPosition.x+dir_x[n],mapPosition.y+dir_y[n]);
    if(newMapPosition.x<0 || newMapPosition.x>=15 ||newMapPosition.y<0 || newMapPosition.y>=15 || !_map.canWalk(newMapPosition.x,newMapPosition.y))
      return;

    int put=rand_int(0,7);
    if(put==0){
        putBomb();
    }
    goal=newMapPosition;
}
void IA::defenseAction(Graph& g,vector<vector<bool>>& dangerous){
    cout<<"recherche en largeur"<<endl;
    goal=g.breadFirstSearch(_map.getMapPosition(Vector2i(pos.x,pos.y)),dangerous);
     cout<<"fin recherche en largeur"<<endl;
}


void IA::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    Personnage::draw(target,states);
}

