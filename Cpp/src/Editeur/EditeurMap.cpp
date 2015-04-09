#include "Editeur/EditeurMap.hpp"

EditeurMap::EditeurMap(sf::Vector2i* s):_map(sf::Vector2f(570,570))
,_save("Sauvegarder"
,sf::Vector2f(100,25),sf::Vector2f(10,10),"Menu")
,input(sf::Vector2f(s->x/2-50,s->y/2-10),sf::Vector2f(100,20),"")
{
    _window_size=s;
    _map.setPosition(sf::Vector2f((s->x/2)-(_map.getSize().x/2),(s->y/2)-(_map.getSize().y/2)));

    _gauche.setSize(Vector2f((_window_size->x-(_map.getPosition().x+_map.getSize().x))/2,_window_size->y));
    _gauche.setPosition(sf::Vector2f(s->x-_gauche.getSize().x,0));
    _gauche.setFillColor(sf::Color::Blue);

    _mur=Ressource::getSprite("surfaces/mur.png");
    _mur.setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+1*HAUTEUR+20));
    _block=Ressource::getSprite("surfaces/block.png");
    _block.setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(HAUTEUR+20)*2));

    _sol=Ressource::getSprite("surfaces/sol.png");
    _sol.setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(HAUTEUR+20)*3));

    for(int i=1;i<5;i++){
        _perso.push_back(Ressource::getSprite("surfaces/sol_p"+to_string(i)+".png",sf::IntRect(0,0,LARGEUR,HAUTEUR)));
        _perso[i-1].setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(HAUTEUR+20)*(i+4)));
    }
    tmp=nullptr;
    _click=false;
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++){
            _spriteTab[i][j]=Ressource::getSprite("surfaces/sol.png");
            _spriteTab[i][j].setPosition(sf::Vector2f(_map.getPosition().x+i*LARGEUR,_map.getPosition().y+j*HAUTEUR));
            _mapTab[i][j]=SOL;
        }

   file="";
   _choiceNameFile=false;


}


EditeurMap::~EditeurMap()
{
    //dtor
}
void EditeurMap::save(){
    ofstream f("res/map/"+file,ios::out | ios::trunc);
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

    if(tmp!=nullptr && pointInRect(_map.getPosition(),sf::Vector2f(_map.getGlobalBounds().width,_map.getGlobalBounds().height),Vector2f(event.mouseButton.x,event.mouseButton.y))){
        sf::Vector2f relativePos(event.mouseButton.x-_map.getPosition().x,event.mouseButton.y-_map.getPosition().y);
        int x=(relativePos.x*15)/570;
        int y=(relativePos.y*15)/570;
        if(_mapTab[x][y]==PERSONNAGE){
            _perso.push_back(Sprite(*_spriteTab[x][y].getTexture(),sf::IntRect(0,0,LARGEUR,HAUTEUR)));
            _perso.back().setPosition(sf::Vector2f(_gauche.getPosition().x+10,_gauche.getPosition().y+(HAUTEUR+20)*(_perso.size()+4)));
        }
        _spriteTab[x][y]=Sprite(*tmp->getTexture());
        _spriteTab[x][y].setPosition(sf::Vector2f(_map.getPosition().x+x*_spriteTab[x][y].getGlobalBounds().width,_map.getPosition().y+y*_spriteTab[x][y].getGlobalBounds().height));
        _mapTab[x][y]=id;
        _click=true;
        if(id==PERSONNAGE)
            tmp=nullptr;

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

    for(int i=0;i<_perso.size();i++){
        if(pointInRect(_perso[i].getPosition(),sf::Vector2f(_perso[i].getGlobalBounds().width,_perso[i].getGlobalBounds().height),Vector2f(event.mouseButton.x,event.mouseButton.y))){
            tmp=new Sprite(*_perso[i].getTexture(),sf::IntRect(0,0,38,38));
            _perso.erase(_perso.begin()+i);
            id=PERSONNAGE;
        }
    }
    if(tmp!=nullptr)
        tmp->setPosition(Vector2f(event.mouseButton.x,event.mouseButton.y));

}
void EditeurMap::onMouseHover(sf::Event& event){
    _save.onEvent(event);
    _hover=_save.getHover();

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
        _mapTab[x][y]=id;
    }
}
void EditeurMap::onEvent(sf::Event& event){
   //SOURIS
    if(_choiceNameFile){
       if( event.type==sf::Event::MouseMoved){
            onMouseHover(event);
            if(_click)
                onMouseMove(event);
        }

       if(event.type==sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
            onMouseClickRight(event);
       if(event.type==sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !_hover)
            onMouseClickLeft(event);
       else if(event.type==sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && _hover)
            clickButtonSave(event);
       if(event.type==sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && !_hover)
            _click=false;
    }

    //CLAVIER
    else{
        input.onEvent(event);
        if(event.type==sf::Event::KeyReleased && event.key.code==sf::Keyboard::Return){
            ofstream f("res/map/"+input.getString(),ios::out | ios::trunc);
            if(!f.good())
                Console::say("Impossible de créer le fichier "+input.getString(),1);
            else{
                f.close();
                file=input.getString();
                _choiceNameFile=true;
                save();
            }
        }

    }
}
void EditeurMap::clickButtonSave(sf::Event& event){

    save();
    _save.onEvent(event);
}

void EditeurMap::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    if(_choiceNameFile){
        target.draw(_map,states);
        target.draw(_gauche,states);
        for(int i=0;i<15;i++)
            for(int j=0;j<15;j++)
                target.draw(_spriteTab[i][j]);
        target.draw(_mur,states);
        target.draw(_block,states);
        target.draw(_sol,states);

        if(tmp!=nullptr){
            target.draw(*tmp,states);
       }
        for(int i=0;i<_perso.size();i++){
            target.draw(_perso[i],states);
        }
        target.draw(_save,states);
    }
    else{
        target.draw(input,states);
    }
}
