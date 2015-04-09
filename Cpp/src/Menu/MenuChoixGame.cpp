#include "MenuChoixGame.hpp"

MenuChoixGame::MenuChoixGame(sf::Vector2i* s,EventManager& event):Menu(s)
{
    sf::Vector2f boutonSize(_window_size->x*0.2,_window_size->y*0.1);
    sf::Vector2f positionBouton(_window_size->x/2-boutonSize.x/2,_window_size->y/2-boutonSize.y-boutonSize.y/2);

    addObs("DeathMatch",new Bouton("Combat à Mort",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*0),"ChoixLevelDeath"));
    addObs("ContreLaMontre",new Bouton("Contre la montre",boutonSize,Vector2f(positionBouton.x,positionBouton.y+0.1*_window_size->y*1),"ChoixLevelMontre"));


    ScreenManager::add(new ChoixLevel(s,"res/map/",DeathMatch,event),"ChoixLevelDeath");
    ScreenManager::add(new ChoixLevel(s,"res/map/",ContreLaMontre,event),"ChoixLevelMontre");

    labelDescription.setFont(Ressource::getFont("default.ttf"));
    labelDescription.setCharacterSize(25);
    labelDescription.setColor(sf::Color::White);
    labelDescription.setString("Description");
    labelDescription.setPosition(Vector2f(s->x/2-labelDescription.getGlobalBounds().width/2,s->y/2+100-labelDescription.getGlobalBounds().height/2));


    description.setFont(Ressource::getFont("default.ttf"));
    description.setCharacterSize(15);
    description.setColor(sf::Color::White);
    description.setString("");
    description.setPosition(Vector2f(s->x/2-description.getGlobalBounds().width/2,s->y/2+150-description.getGlobalBounds().height/2));


    _hover=false;

    vector<string> liste=listOfFiles("res/typeGame/");
    for(int i=0;i<liste.size();i++){
        cout<<"fichier "<<liste[i]<<endl;
        ifstream f("res/typeGame/"+liste[i]);
        if(!f.good()){
            Console::say("Erreur Lecture fichier description ",1);
        }
        string ligne;
        string total;
        while(getline(f, ligne)){
            cout<<ligne<<endl;
            total+=ligne;
            total+="\n";
        }
        typeDescription[liste[i]]=total;
        f.close();
    }


}

MenuChoixGame::~MenuChoixGame()
{
    //dtor
}

void MenuChoixGame::onEvent(sf::Event& event){
    _hover=false;
    for(map<string,Observateur*>::iterator it=_gui.begin();it!=_gui.end();it++){
        it->second->onEvent(event);
        bool b=_hover;
        _hover=_hover||it->second->getHover();
        if(_hover && !b){
            cout<<"nom bouton "<<it->first<<endl;
            buttonHover=it->first;
        }
    }
    if(!_hover)
        buttonHover="";
}

void MenuChoixGame::update(sf::Time& time){
    for(map<string,Observateur*>::iterator it=_gui.begin();it!=_gui.end();it++){
        it->second->update();
        if(_hover){
            if(typeDescription.find(buttonHover)!=typeDescription.end()){
                description.setString(L""+typeDescription[buttonHover]);
                description.setPosition(Vector2f(_window_size->x/2-description.getGlobalBounds().width/2,_window_size->y/2+150-description.getGlobalBounds().height/2));
            }
            else
                Console::say("Bouton "+buttonHover +" nexiste pas ",1);
        }
        else{
            description.setString("");
            buttonHover="";
        }
    }

}
void MenuChoixGame::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_background);
    for(map<string,Observateur*>::const_iterator it=_gui.begin();it!=_gui.end();it++)
       target.draw(*it->second,states);
    if(_hover){
        target.draw(labelDescription);
        target.draw(description);
    }


}
