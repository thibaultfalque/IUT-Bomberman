#include "Personnage.hpp"

Personnage::Personnage(sf::Vector2f position,int numPersonnage, Map & __map,BombManager & bm):_map(__map),_bombeManager(bm)
{
    numType = numPersonnage;
    pos=position;
    etapePas = 0;
    direction = 0;
    pixelParSecondes = 70;
    vitesse=sf::Vector2f(0,0);
    nbBombeMax=1;
    nbBombe=2;
    launcher=false;
    pusher=false;
    degatsBombes=2;

    for(int y=0;y<4;y++)
    for(int x=0;x<9;x++){
        _sprites[y][x]=Ressource::getSprite("bombermanspritesP"+to_string(numType)+".png",IntRect(38*x+9,38*y+5,20,30));
        _sprites[y][x].setPosition(pos);
        _sprites[y][x].setOrigin(10,25);
    }

    tempsTotalPas=0;
    tempsTotalDelta=0;

}

void Personnage::setVitesse(float vit){
    pixelParSecondes=vit;
    if(pixelParSecondes>150)
        pixelParSecondes=150;
    if(pixelParSecondes<30)
        pixelParSecondes=30;
}
bool Personnage::setnbBombeMax(int nb){

    nbBombeMax=nb;
    if(nbBombeMax<1){
        nbBombeMax=1;
        return false;
    }
    if(nbBombeMax>10){
        nbBombeMax=10;
        return false;
    }
    return true;
}
void Personnage::addBombe(){
    if(nbBombe<nbBombeMax)
        nbBombe++;
}
void Personnage::removeBombe(){
    if(nbBombe>0)
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
float Personnage::getVitesse(){
    return pixelParSecondes;
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

void Personnage::update(sf::Time& tps){
}

void Personnage::graphicUpdate(sf::Time& tps){
    //TODO METTRE DEUX FLOAT TEMPS TOTALS !!
    for(int y=0;y<4;y++)
    for(int x=0;x<9;x++)
        _sprites[y][x].setPosition(pos);

    if(tempsTotalPas>=0.06){
        tempsTotalPas=0;
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
    tempsTotalDelta=0;
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
            if(!_map.canWalk(x,y,numType))
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
    return FloatRect(newPos+Vector2f(-5,-2),Vector2f(10,4));

}

void Personnage::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    //BAS DROITE HAUT GAUCHE
    target.draw(_sprites[direction][etapePas]);
}
void Personnage::putBomb(){

}



void Personnage::onEvent(sf::Event & event){}
