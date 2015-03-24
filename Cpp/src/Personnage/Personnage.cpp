#include "Personnage.hpp"


Personnage::Personnage(sf::Vector2f position, Map & __map):_map(__map)
{
    pos=position;
    etapePas = 0;
    direction = 0;
    // vitesse de déplacement mis au pif, doit surement etre modifié
    vitesse=sf::Vector2f(10,10);
    nbBombeMax=1;
    nbBombe=1;
    launcher=false;
    pusher=false;
    //bombe=new BombeNormale();
    degatsBombes=2;
    for(int y=0;y<4;y++)
    for(int x=0;x<9;x++)
        _sprites[y][x]=Ressource::getSprite("bombermansprites.png",IntRect(38*x,38*y,38,38));
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
    vitesse = Vector2f(0,0);
    float pixelParSecondes = 50;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        vitesse.x -= pixelParSecondes;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        vitesse.x += pixelParSecondes;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        vitesse.y -= pixelParSecondes;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        vitesse.y += pixelParSecondes;

    if(vitesse.x*vitesse.y!=0){
        vitesse = (vitesse/sqrt(vitesse.x*vitesse.x + vitesse.y*vitesse.y))*pixelParSecondes;
    }


    moveTo(pos +vitesse*deltaUpdate.getElapsedTime().asSeconds());

    cout << pos.x << endl;


    //GRAPHIC UPDATE

    for(int y=0;y<4;y++)
    for(int x=0;x<9;x++)
        _sprites[y][x].setPosition(pos);

    if(timerPas.getElapsedTime().asSeconds()>=0.1){
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

void Personnage::moveTo(sf::Vector2f newPos){
cout << "ok" << endl;
    Vector2i realPos =Vector2i((int)pos.x,(int)pos.y);
    Vector2i realNewPos = Vector2i((int)newPos.x,(int)newPos.y);
    cout << realPos.x << "|" << realPos.y << endl;
    cout << realNewPos.x << "|" << realNewPos.y << endl;

    Vector2i diff = realPos-realNewPos;
    cout << diff.x << endl;
    cout << diff.y << endl;
    if(canMoveTo(realNewPos) || !canMoveTo(realPos))
        pos=newPos;
    else if(!(abs(diff.x)<=1 && abs(diff.y)<=1) ){
        Vector2i middle = (realPos+realNewPos);
        cout << middle.x << endl;
        cout << middle.y << endl;
        middle.x/=2;

        middle.y/=2;
        cout << middle.x << endl;
        cout << middle.y << endl;
        if(canMoveTo(middle)){  cout << "ici2" << endl;
            pos = Vector2f(middle.x,middle.y);
            moveTo(newPos);

        }
        else{
        cout << "ici" << endl;
            moveTo(Vector2f(middle.x,middle.y));

        }
    }
}

bool Personnage::canMoveTo(sf::Vector2i newPos){

    if(newPos.x<0 || newPos.y<0) // conditionTemporaire
    return false;

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

