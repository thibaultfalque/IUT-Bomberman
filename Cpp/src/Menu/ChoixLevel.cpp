#include "ChoixLevel.hpp"

ChoixLevel::ChoixLevel(sf::Vector2i* s,string dir,int type,EventManager& event):Menu(s),eventManager(event)
{
    sf::Vector2f boutonSize(_window_size->x*0.2,_window_size->y*0.1);
    vector<string> listeFile=listOfFiles(dir);
    for(unsigned int i=0;i<listeFile.size();i++){
        if(listeFile[i]=="." || listeFile[i]=="..")
            continue;
        listLevel.push_back(new ViewLevel(dir+listeFile[i],sf::Vector2f(_window_size->x/2-125*i,_window_size->y/2-100)));
    }
    for(int i=0;i<3 && i!=listLevel.size();i++){
        view[i]=listLevel[i];
    }
    if(type==DeathMatch){
        _bouton=new Bouton("Jouer",boutonSize,sf::Vector2f(600,500),"Game");
    }
    else if(type==ContreLaMontre){
        _bouton=new Bouton("Jouer",boutonSize,sf::Vector2f(700,500),"Game");
    }

}

ChoixLevel::~ChoixLevel()
{
    //dtor
}
void ChoixLevel::onEvent(sf::Event & event){
    _bouton->onEvent(event);
    if(_bouton->getHover()){
       int j=-1;
       for(int i=0;i<3 && i!=listLevel.size();i++)
          if(view[i]!=nullptr)
            if(view[i]->isClick())
                j=i;
        if(j!=-1){
            ScreenManager::add(new Game(_window_size,eventManager,view[j]->getNameFile()),"Game");
            _bouton->onEvent(event);
        }
    }
    for(int i=0;i<3 && i!=listLevel.size();i++){
        if(view[i]!=nullptr)
            view[i]->onEvent(event);
    }
}
void ChoixLevel::update(sf::Time& tps){
    _bouton->update();
    for(int i=0;i<3 && i!=listLevel.size();i++){
        if(view[i]!=nullptr)
            view[i]->update(tps);
    }
}
void ChoixLevel::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_background);
    target.draw(*_bouton,states);
    for(int i=0;i<3 && i!=listLevel.size();i++){
        if(view[i]!=nullptr)
            target.draw(*view[i]);
    }
}
