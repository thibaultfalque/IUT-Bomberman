#include "Map.hpp"
Map::Map(string str):_matrix(5),pos(0,0)
{
    string ligne;

    ligne=readFileMap(str);
    _matrix.resize(_size.x);
    for(unsigned int i=0;i<_size.x;i++)
        for(unsigned int j=0;j<_size.y;j++){
            switch(ligne[(i*_size.x)+j]){
                case MUR:
                    _matrix[i].push_back(new Mur("surfaces/mur.png",false,sf::Vector2f(LARGEUR*i,HAUTEUR*j)));
                break;
                case BLOCK:
                    _matrix[i].push_back(new Block("surfaces/block.png",false,sf::Vector2f(LARGEUR*i,HAUTEUR*j)));
                break;
                case SOL:
                    _matrix[i].push_back(new Sol("surfaces/sol.png",true,sf::Vector2f(LARGEUR*i,HAUTEUR*j)));
                break;
            }
        }
}

Map::~Map()
{
    //dtor
}
void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    for(unsigned int i=0;i<_size.x;i++){
        for(unsigned int j=0;j<_size.y;j++){
            target.draw(*_matrix[i][j],states);
        }
    }

}
string Map::readFileMap(string str){
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
    _size.x=string_to_int(tailles[0]);
    _size.y=string_to_int(tailles[1]);


    getline(f,t);
    f.close();
    return t;
}
Case* Map::getCase(int x,int y){
    return _matrix[x][y];
}
sf::Vector2i& Map::getSize(){
    return _size;
}

Vector2i Map::getMapPosition(Vector2i screenPosition){
    screenPosition.x = screenPosition.x-pos.x;
    screenPosition.y = screenPosition.y-pos.y;
    screenPosition.x = floor(screenPosition.x/(float)LARGEUR);
    screenPosition.y = floor(screenPosition.y/(float)HAUTEUR);
    if(screenPosition.x<0 || screenPosition.x>=_size.x || screenPosition.y <0 || screenPosition.y >= _size.y){
        screenPosition.x=-1;
        screenPosition.y=-1;
    }

    return screenPosition;
}

bool Map::canWalk(int x, int y){
    if(x<0||x>_matrix.size()||y<0||y>_matrix[x].size())
        return false;
    return _matrix[x][y]->canWalk();
}
