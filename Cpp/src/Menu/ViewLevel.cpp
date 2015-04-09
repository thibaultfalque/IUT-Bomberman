#include "ViewLevel.hpp"

ViewLevel::ViewLevel(string file,sf::Vector2f pos):position(pos)
{
    string ligne;
    ligne=readFileMap(file);

    rect.setSize(sf::Vector2f(300,300));
    rect.setPosition(pos);


    label.setFont(Ressource::getFont("default.ttf"));
    label.setCharacterSize(25);
    label.setColor(sf::Color::White);
    label.setString(file);
    label.setPosition(Vector2f(position.x+position.x/2-label.getGlobalBounds().width/2,position.y+position.y/2-label.getGlobalBounds().height/2));

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
            sprites[i][j].setPosition(sf::Vector2f(position.x+16*i,position.y+label.getGlobalBounds().height+16*j));
        }

}

ViewLevel::~ViewLevel()
{
    //dtor
}
string ViewLevel::readFileMap(string str){
    ifstream f(str);
    if(!f.good()){
        perror("echec de l'ouverture");
        exit(1);
    }
    string t;
    getline(f,t);
    vector<string> tailles;
    tailles=explode(t,' ');
    if(tailles.size()!=2){
        cerr<<"Fichier map mal forme: erreur taille map"<<endl;
        exit(1);
    }
    getline(f,t);
    f.close();
    return t;
}
void ViewLevel::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(label);
    for(int i=0;i<15;i++)
            for(int j=0;j<15;j++)
                target.draw(sprites[i][j]);
}

void ViewLevel::onEvent(sf::Event& event){

}
