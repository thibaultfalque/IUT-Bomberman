#include "Map.hpp"

Map::Map(string str):_matrix(5)
{
    string ligne;
    ligne=readFileMap(str);
    cout<<"ligne "<<ligne.size()<<endl;
    _matrix.resize(_size.x);
    for(unsigned int i=0;i<_size.x;i++)
        for(unsigned int j=0;j<_size.y;j++){
            cout<<"j "<<j<<endl;
            cout<<"carac "<<ligne[(i*_size.x)+j]<<endl;
            switch(ligne[(i*_size.x)+j]){
                case '0':
                    _matrix[i].push_back(new Mur("surfaces/mur.png",false,sf::Vector2f(LARGEUR*i,HAUTEUR*j)));
                break;
                case '1':
                    _matrix[i].push_back(new Block("surfaces/block.png",false,sf::Vector2f(LARGEUR*i,HAUTEUR*j)));
                break;
                case '2':
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
        cout<<"i "<<i<<endl;
        for(unsigned int j=0;j<_size.y;j++){
            cout<<"j "<<j<<endl;
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
        cerr<<"fichier map mal forme: erreur taille map"<<endl;
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
