#include "Explosion.hpp"
#include "Map.hpp"
using namespace sf;
using namespace std;
void Explosion::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(Sprite s:sprites[etape])
        target.draw(s,states);
}

void Explosion::update()
{
    if(_clock.getElapsedTime().asSeconds()>0.1){
        _clock.restart();
        if(etape>0)
        etape--;
        else
        needDestroy=true;
    }

}

Explosion::Explosion(sf::Vector2i center, int power, int numPerso,Map & _map)
{
    needDestroy=false;
    etape=3;
    for(int i=0;i<4;i++){
        Sprite tmp=Ressource::getSprite("explosionP"+to_string(numPerso)+".png"
                                        ,IntRect(LARGEUR,HAUTEUR*(1+i*4),LARGEUR,HAUTEUR));
        Vector2i pos=_map.getScreenPosition(center);
        tmp.setPosition(pos.x,pos.y);
        sprites[i].push_back(tmp);
        tmp=Ressource::getSprite("explosionP"+to_string(numPerso)+".png"
                                ,IntRect(LARGEUR*2,HAUTEUR*(1+i*4),LARGEUR,HAUTEUR));

        Sprite tmp2=Ressource::getSprite("explosionP"+to_string(numPerso)+".png"
                                ,IntRect(LARGEUR*3,HAUTEUR*(1+i*4),LARGEUR,HAUTEUR));

        for(int j=0;j<power;j++){
            if(!_map.canWalk(center.x+1+j,center.y)){
                break;
            }
            if(j==power-1){
                tmp2.setPosition(pos.x+(j+1)*LARGEUR,pos.y);
                sprites[i].push_back(tmp2);
                continue;
            }
            tmp.setPosition(pos.x+(j+1)*LARGEUR,pos.y);
            sprites[i].push_back(tmp);

        }
        tmp.rotate(90);
        tmp2.rotate(90);
        //tmp.
        for(int j=0;j<power;j++){
            if(!_map.canWalk(center.x,center.y+1+j)){
                break;
            }
            if(j==power-1){
                tmp2.setPosition(pos.x+LARGEUR,pos.y+(j+1)*HAUTEUR);
                sprites[i].push_back(tmp2);
                continue;
            }
            tmp.setPosition(pos.x+LARGEUR,pos.y+(j+1)*HAUTEUR);
            sprites[i].push_back(tmp);
        }//*
        tmp.rotate(90);
        tmp2.rotate(90);
        for(int j=0;j<power;j++){
            if(!_map.canWalk(center.x-1-j,center.y)){
                break;
            }
            if(j==power-1){
                tmp2.setPosition(pos.x-j*LARGEUR,pos.y+HAUTEUR);
                sprites[i].push_back(tmp2);
                continue;
            }
            tmp.setPosition(pos.x-j*LARGEUR,pos.y+HAUTEUR);
            sprites[i].push_back(tmp);
        }//*
        tmp.rotate(90);
        tmp2.rotate(90);
        for(int j=0;j<power;j++){
            if(!_map.canWalk(center.x,center.y-1-j)){
                break;
            }
            if(j==power-1){
                tmp2.setPosition(pos.x,pos.y-j*HAUTEUR);
                sprites[i].push_back(tmp2);
                continue;
            }
            tmp.setPosition(pos.x,pos.y-j*HAUTEUR);
            sprites[i].push_back(tmp);
        } //*/
    }
}

bool Explosion::getNeedDestroy()
{
    return needDestroy;
}
