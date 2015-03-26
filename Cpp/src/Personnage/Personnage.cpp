#include "Personnage.hpp"

Personnage::Personnage(sf::Vector2f position,const string& str, Map & __map,BombManager & bm):_map(__map),_bombeManager(bm)
{
    pos=position;
    etapePas = 0;
    direction = 0;
    // vitesse de déplacement mis au pif, doit surement etre modifié
    vitesse=sf::Vector2f(10,10);
    nbBombeMax=1;
    nbBombe=5;
    launcher=false;
    pusher=false;
    //bombe=new BombeNormale();
    degatsBombes=2;

    _sprite=Ressource::getSprite(str,sf::IntRect(0,0,38,38));
    _sprite.setPosition(pos);

    for(int y=0;y<4;y++)
    for(int x=0;x<9;x++)
        _sprites[y][x]=Ressource::getSprite(str,IntRect(38*x+9,38*y+5,20,30));

}

void Personnage::setVitesse(sf::Vector2f vit){
    vitesse=vit;
}
void Personnage::setnbBombeMax(int nb){
    nbBombeMax=nb;
}
void Personnage::setnbBombe(int nb){
    nbBombe=nb;
}
void Personnage::setdegatsBombes(int d){
    degatsBombes=d;
}
void Personnage::setLauncher(bool l){
    launcher=l;
}
void Personnage::setPusher(bool p){
    pusher=p;
}

sf::Vector2f Personnage::getPos(){
    return pos;
}
sf::Vector2f Personnage::getVitesse(){
    return vitesse;
}
int Personnage::getnbBombeMax(){
    return nbBombeMax;
}
int Personnage::getnbBombe(){
    return nbBombe;
}
int Personnage::getdegatsBombes(){
    return degatsBombes;
}

void Personnage::addBonusMalus(BonusMalus b){

}


void Personnage::update(){
}

void Personnage::moveTo(sf::Vector2f newPos){
    if(pos==newPos || canMoveTo(Vector2i((int)newPos.x,(int)newPos.y)) || !canMoveTo(Vector2i((int)pos.x,(int)pos.y)))
        pos = newPos;
}

bool Personnage::canMoveTo(sf::Vector2i newPos){

    Vector2i hg = _map.getMapPosition(newPos+Vector2i(0,15));
    Vector2i bd = _map.getMapPosition(newPos+Vector2i(20,30));
    for(int x=hg.x;x<=bd.x;x++)
        for(int y=hg.y;y<=bd.y;y++){
            if(!_map.canWalk(x,y))
                return false;

        }
    return true;

}

Personnage::~Personnage()
{
    //dtor
}

void Personnage::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    //BAS DROITE HAUT GAUCHE



    target.draw(_sprites[direction][etapePas]);
}

