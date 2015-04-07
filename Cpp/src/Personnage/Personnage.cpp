#include "Personnage.hpp"

Personnage::Personnage(sf::Vector2f position,int numPersonnage, Map & __map,BombManager & bm):_map(__map),_bombeManager(bm)
{
    numType = numPersonnage;
    pos=position;
    etapePas = 0;
    direction = 0;
    // vitesse de déplacement mis au pif, doit surement etre modifié
    vitesse=sf::Vector2f(10,10);
    nbBombeMax=1;
    nbBombe=12;
    launcher=false;
    pusher=false;
    //bombe=new BombeNormale();
    degatsBombes=2;

    for(int y=0;y<4;y++)
    for(int x=0;x<9;x++){
        _sprites[y][x]=Ressource::getSprite("bombermanspritesP"+to_string(numType)+".png",IntRect(38*x+9,38*y+5,20,30));
        _sprites[y][x].setPosition(pos);
    }

}

void Personnage::setVitesse(sf::Vector2f vit){
    vitesse=vit;
}
void Personnage::setnbBombeMax(int nb){
    nbBombeMax=nb;
}
void Personnage::addBombe(){
    nbBombe++;
}
void Personnage::removeBombe(){
    nbBombe--;
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
void Personnage::setnbBombe(int nb){
    nbBombe=nb;
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

int Personnage::getType(){
    return numType;
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

    FloatRect hitBox = getHitBox(newPos);
    Vector2i hg = _map.getMapPosition(Vector2i(hitBox.left,hitBox.top));
    Vector2i bd = _map.getMapPosition(Vector2i(hitBox.left+hitBox.width,hitBox.top+hitBox.height));

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

sf::FloatRect Personnage::getHitBox(sf::Vector2i newPos)
{
    return getHitBox(Vector2f(newPos.x,newPos.y));
}

sf::FloatRect Personnage::getHitBox()
{
    return getHitBox(pos);
}

sf::FloatRect Personnage::getHitBox(sf::Vector2f newPos)
{
    return FloatRect(newPos+Vector2f(5,23),Vector2f(10,4));

}

void Personnage::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    //BAS DROITE HAUT GAUCHE
    target.draw(_sprites[direction][etapePas]);
}
void Personnage::putBomb(){

}



void Personnage::onEvent(sf::Event & event){}
