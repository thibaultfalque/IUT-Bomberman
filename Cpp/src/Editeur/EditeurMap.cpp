#include "Editeur/EditeurMap.hpp"

EditeurMap::EditeurMap(sf::Vector2i* s):_map(sf::Vector2f(570,570)),_save("Sauvegarder",sf::Vector2f(50,20),sf::Vector2f(0,0),"Menu")
{
    sf::Vector2f sizeTexture(38,38);
    _window_size=s;
    _map.setPosition(sf::Vector2f((s->x/2)-(_map.getSize().x/2),(s->y/2)-(_map.getSize().y/2)));

    _gauche.setSize(Vector2f((_window_size->x-(_map.getPosition().x+_map.getSize().x))/2,_window_size->y));
    _gauche.setPosition(sf::Vector2f(s->x-_gauche.getSize().x,0));
    _gauche.setFillColor(sf::Color::Blue);

/*    _mur=new Mur("surfaces/mur.png",false,sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+1*sizeTexture.y+20));
    _block=new Block("surfaces/block.png",false,sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(sizeTexture.y+20)*2));
    _sol=new Sol("surfaces/sol.png",true,sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(sizeTexture.y+20)*3));

        for(int i=1;i<5;i++){
            _ia.push_back(new IA(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(sizeTexture.y+20)*(i+3)),"bombermanspritesP"+to_string(i)+".png"));
        }*/

    _mur=Ressource::getSprite("surfaces/mur.png");
    _mur.setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+1*sizeTexture.y+20));
    _block=Ressource::getSprite("surfaces/block.png");
    _block.setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(sizeTexture.y+20)*2));

    _sol=Ressource::getSprite("surfaces/sol.png");
    _sol.setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(sizeTexture.y+20)*3));
    _humain=Ressource::getSprite("bombermanspritesP0.png",sf::IntRect(0,0,38,38));
    _humain.setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(sizeTexture.y+20)*4));
        for(int i=1;i<5;i++){
            _ia.push_back(Ressource::getSprite("bombermanspritesP"+to_string(i)+".png",sf::IntRect(0,0,38,38)));
            _ia[i-1].setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(sizeTexture.y+20)*(i+4)));
        }
     tmp=nullptr;
     _click=false;
     for(int i=0;i<15;i++)
        for(int j=0;j<15;j++){
            _spriteTab[i][j]=Ressource::getSprite("surfaces/sol.png");
            _spriteTab[i][j].setPosition(sf::Vector2f(_map.getPosition().x+i*38,_map.getPosition().y+j*38));
            _mapTab[i][j]=SOL;
        }

}


EditeurMap::~EditeurMap()
{
    //dtor
}
void EditeurMap::save(){
    ofstream f("res/map/map2.lvl",ios::out | ios::trunc);
    if(!f.good()){
        perror("echec de l'ouverture");
        exit(1);
    }
    f<<15<<" "<<15<<endl;
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            f<<_mapTab[i][j];
    f.close();


}
void EditeurMap::onMouseClickLeft(sf::Event& event){
    if(pointInRect(_save.getPosition(),_save.getSize(),sf::Vector2f(event.mouseButton.x,event.mouseButton.y))){
        save();
        _save.onEvent(event);
    }

    if(tmp!=nullptr && pointInRect(_map.getPosition(),sf::Vector2f(_map.getGlobalBounds().width,_map.getGlobalBounds().height),Vector2f(event.mouseButton.x,event.mouseButton.y))){
        sf::Vector2f relativePos(event.mouseButton.x-_map.getPosition().x,event.mouseButton.y-_map.getPosition().y);
        int x=(relativePos.x*15)/570;
        int y=(relativePos.y*15)/570;
        _spriteTab[x][y]=Sprite(*tmp->getTexture());
        _spriteTab[x][y].setPosition(sf::Vector2f(_map.getPosition().x+x*_spriteTab[x][y].getGlobalBounds().width,_map.getPosition().y+y*_spriteTab[x][y].getGlobalBounds().height));
        //tmp=nullptr;
        _click=true;
        _mapTab[x][y]=id;
    }
}

void EditeurMap::onMouseClickRight(sf::Event& event){
    if(pointInRect(_mur.getPosition(),sf::Vector2f(_mur.getGlobalBounds().width,_mur.getGlobalBounds().height),Vector2f(event.mouseButton.x,event.mouseButton.y))){
        tmp=new Sprite(*_mur.getTexture());
        id=MUR;
    }
    if(pointInRect(_block.getPosition(),sf::Vector2f(_block.getGlobalBounds().width,_block.getGlobalBounds().height),Vector2f(event.mouseButton.x,event.mouseButton.y))){
        tmp=new Sprite(*_block.getTexture());
        id=BLOCK;
    }
    if(pointInRect(_sol.getPosition(),sf::Vector2f(_sol.getGlobalBounds().width,_sol.getGlobalBounds().height),Vector2f(event.mouseButton.x,event.mouseButton.y))){
        tmp=new Sprite(*_sol.getTexture());
        id=SOL;
    }
    if(pointInRect(_humain.getPosition(),sf::Vector2f(_humain.getGlobalBounds().width,_humain.getGlobalBounds().height),Vector2f(event.mouseButton.x,event.mouseButton.y)))
        tmp=new Sprite(*_humain.getTexture(),sf::IntRect(0,0,38,38));
    for(int i=0;i<_ia.size();i++){
        if(pointInRect(_ia[i].getPosition(),sf::Vector2f(_ia[i].getGlobalBounds().width,_humain.getGlobalBounds().height),Vector2f(event.mouseButton.x,event.mouseButton.y)))
            tmp=new Sprite(*_ia[i].getTexture(),sf::IntRect(0,0,38,38));
    }
    if(tmp!=nullptr)
        tmp->setPosition(Vector2f(event.mouseButton.x,event.mouseButton.y));

}
void EditeurMap::onMouseHover(sf::Event& event){

   if(tmp!=nullptr){
        tmp->setPosition(sf::Vector2f(event.mouseMove.x-tmp->getGlobalBounds().width/2,event.mouseMove.y-tmp->getGlobalBounds().height/2));
   }
}
void EditeurMap::onMouseMove(sf::Event& event){
    if(tmp!=nullptr && pointInRect(_map.getPosition(),sf::Vector2f(_map.getGlobalBounds().width,_map.getGlobalBounds().height),Vector2f(event.mouseMove.x,event.mouseMove.y))){
        sf::Vector2f relativePos(event.mouseMove.x-_map.getPosition().x,event.mouseMove.y-_map.getPosition().y);
        int x=(relativePos.x*15)/570;
        int y=(relativePos.y*15)/570;
        _spriteTab[x][y]=Sprite(*tmp->getTexture());
        _spriteTab[x][y].setPosition(sf::Vector2f(_map.getPosition().x+x*_spriteTab[x][y].getGlobalBounds().width,_map.getPosition().y+y*_spriteTab[x][y].getGlobalBounds().height));
        //tmp=nullptr;
        _mapTab[x][y]=id;
    }
}
void EditeurMap::onEvent(sf::Event& event){
   if( event.type==sf::Event::MouseMoved){
        onMouseHover(event);
        if(_click)
            onMouseMove(event);
    }
   if(event.type==sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
        onMouseClickRight(event);
   if(event.type==sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        onMouseClickLeft(event);
    if(event.type==sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        _click=false;

}


void EditeurMap::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_map,states);
    target.draw(_gauche,states);
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            target.draw(_spriteTab[i][j]);
    target.draw(_mur,states);
    target.draw(_block,states);
    target.draw(_sol,states);

    target.draw(_humain,states);
    if(tmp!=nullptr){
        target.draw(*tmp,states);
   }
    for(int i=0;i<_ia.size();i++){
        target.draw(_ia[i],states);
    }
    target.draw(_save,states);

}
