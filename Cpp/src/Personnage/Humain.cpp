#include "Humain.hpp"

Humain::Humain(const sf::Vector2f& position,const string& str,Map & __map, EventManager & _em,BombManager & bm):Personnage(position,str,__map,bm),_eventManager(_em)
{

    _bomb.push_back(new Bomb("bombeP1.png",sf::Vector2f(0,0),5));
    _bomb.push_back(new Bomb("bombeP1.png",sf::Vector2f(0,0),5));
    _bomb.push_back(new Bomb("bombeP1.png",sf::Vector2f(0,0),5));
    _bomb.push_back(new Bomb("bombeP1.png",sf::Vector2f(0,0),5));
    _bomb.push_back(new Bomb("bombeP1.png",sf::Vector2f(0,0),5));
    _bomb.push_back(new Bomb("bombeP1.png",sf::Vector2f(0,0),5));

}

Humain::~Humain()
{
    //dtor
}
void Humain::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    Personnage::draw(target,states);
}
void Humain::onEvent(sf::Event& event ){
    if(event.key.code==_eventManager.getEventKey("Poser bombe")){
        sf::Vector2i p=_map.getMapPosition(sf::Vector2i((int)pos.x,(int)pos.y));
        if(nbBombe!=0 && !_bomb.empty()){
            _bombeManager.putBomb(p,pos,_bomb.back());
            _bomb.pop_back();
            nbBombe--;
            cout<<"nbBombe "<<nbBombe<<endl;
        }
    }
}
void Humain::update(){
    vitesse = Vector2f(0,0);
    float pixelParSecondes = 70;
    if(_eventManager.getEventState("Gauche"))
        vitesse.x -= pixelParSecondes;
    if(_eventManager.getEventState("Droite"))
        vitesse.x += pixelParSecondes;
    if(_eventManager.getEventState("Haut"))
        vitesse.y -= pixelParSecondes;
    if(_eventManager.getEventState("Bas"))
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
