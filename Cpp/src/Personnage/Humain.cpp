#include "Humain.hpp"

Humain::Humain(const sf::Vector2f& position,int numPersonnage,Map & __map, EventManager & _em,BombManager & bm)
    :Personnage(position,numPersonnage,__map,bm),_eventManager(_em)
{

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
        putBomb();
    }
}
void Humain::update(sf::Time& tps){
    tempsTotalDelta+=tps.asSeconds();
    tempsTotalPas+=tps.asSeconds();
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

    moveTo(pos +vitesse*tempsTotalDelta);

    //GRAPHIC UPDATE
    graphicUpdate(tps);

}

void Humain::putBomb(){
    sf::Vector2i p=_map.getMapPosition(sf::Vector2i((int)pos.x,(int)pos.y));
        if(nbBombe!=0){
            bool succedPut=_bombeManager.putBomb(*this,new Bomb(*this,degatsBombes));
            if(succedPut){
                removeBombe();
            }
        }
}
