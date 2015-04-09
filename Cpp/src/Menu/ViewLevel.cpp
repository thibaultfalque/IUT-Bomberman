#include "ViewLevel.hpp"

ViewLevel::ViewLevel(string file,sf::Vector2f pos):position(pos),file(file)
{
    _hover=false;
    _click=false;
    string ligne;
    ligne=readFileMap(file);
    _size=sf::Vector2f(275,275);
    rect.setSize(_size);
    rect.setPosition(pos);
    rect.setFillColor(sf::Color::Transparent);

    label.setFont(Ressource::getFont("defaut.ttf"));
    label.setCharacterSize(20);
    label.setColor(sf::Color::White);
    label.setString(file);
    label.setPosition(Vector2f(position.x+_size.x/2-label.getGlobalBounds().width/2,position.y+label.getGlobalBounds().height/2));

   for(int i=0;i<15;i++)
        for(int j=0;j<15;j++){
            switch(ligne[(i*15)+j]){
                case '0':
                    sprites[i][j]=sf::Sprite(Ressource::getTexture("surfaces/mur_mini.png"));
                break;
                case '1':
                    sprites[i][j]=sf::Sprite(Ressource::getTexture("surfaces/block_mini.png"));
                break;
                case '2':
                    sprites[i][j]=sf::Sprite(Ressource::getTexture("surfaces/sol_mini.png"));
                break;
                case '3':
                    sprites[i][j]=sf::Sprite(Ressource::getTexture("surfaces/sol_mini.png"));
                break;

            }
            sprites[i][j].setPosition(sf::Vector2f(position.x+12.5+16*i,position.y+label.getGlobalBounds().height+16*j+20));
        }

}

ViewLevel::~ViewLevel()
{
    //dtor
}
string ViewLevel::readFileMap(string str){
    ifstream f(str);
    if(!f.good()){
        cerr<<"echec de l'ouverture de "<<str<<endl;
        exit(1);
    }
    string t;
    getline(f,t);
    vector<string> tailles;
    tailles=explode(t,' ');
    if(tailles.size()!=2){
        cerr<<"Fichier map "<<str<<" mal forme: erreur taille map"<<endl;
        exit(1);
    }
    getline(f,t);
    f.close();
    return t;
}
void ViewLevel::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(rect);
    target.draw(label);
    for(int i=0;i<15;i++)
            for(int j=0;j<15;j++)
                target.draw(sprites[i][j]);
}

void ViewLevel::onEvent(sf::Event& event){
    if( event.type==sf::Event::MouseMoved)
        onMouseHover(event);
    if(event.type==sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        onMouseClick(event);
}
void ViewLevel::onMouseHover(sf::Event& event){
    _hover=pointInRect(position,_size,Vector2f(event.mouseMove.x,event.mouseMove.y));
}
void ViewLevel::onMouseClick(sf::Event& event){
    if(_hover){
        _click=true;
    }
    else{
        _click=false;
    }
}
void ViewLevel::update(sf::Time& tps){
    if(_hover || _click){
        rect.setOutlineColor(sf::Color::Red);
        rect.setOutlineThickness(5);
    }
    else{
        rect.setOutlineThickness(0);
    }
}
string ViewLevel::getNameFile(){
    return file;
}
bool ViewLevel::isClick(){
    return _click;
}
