#include "Map.hpp"
#include "noClass/fn_string.hpp"
#include "BombManager.hpp"

Map::Map(string str,const sf::Vector2i& window_size,BombManager & bm):_bombManager(bm)
{
    string ligne;

    ligne=readFileMap(str);

    _matrix.resize(_size.x);

    pos=sf::Vector2i(window_size.x/2-(_size.x*LARGEUR)/2,window_size.y/2-(_size.x*HAUTEUR)/2);

    for(unsigned int i=0;i<_size.x;i++)
        for(unsigned int j=0;j<_size.y;j++){

            switch(ligne[(i*_size.y)+j]){
                case '0':
                    _matrix[i].push_back(new Mur("surfaces/mur.png",false,sf::Vector2f(pos.x+LARGEUR*i,pos.y+HAUTEUR*j)));
                break;
                case '1':
                    _matrix[i].push_back(new Block("surfaces/block.png",false,sf::Vector2f(pos.x+LARGEUR*i,pos.y+HAUTEUR*j)));
                break;
                case '2':
                    _matrix[i].push_back(new Sol("surfaces/sol.png",true,sf::Vector2f(pos.x+LARGEUR*i,pos.y+HAUTEUR*j)));
                break;
                case '3':
                    _matrix[i].push_back(new Sol("surfaces/sol.png",true,sf::Vector2f(pos.x+LARGEUR*i,pos.y+HAUTEUR*j)));
                    _posDepartPerso.push_back(Vector2i(i,j));
                break;

            }
        }
}
vector<Vector2i>& Map::getPosDepartPerso(){
    return _posDepartPerso;
}

Map::~Map()
{
    for(int i=0;i<_matrix.size();i++)
        for(int j=0;j<_matrix[i].size();j++)
            delete _matrix[i][j];


}
void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const{


    for(unsigned int i=0;i<_matrix.size();i++){
        for(unsigned int j=0;j<_matrix[i].size();j++){
            target.draw(*_matrix[i][j],states);
        }
    }
    for(BonusMalus *b:_bonusMalus)
        target.draw(*b,states);
}
sf::Vector2i& Map::getPosition(){
    return pos;
}

void Map::checkBonusMalus(Personnage * p){
    FloatRect hb_p = p->getHitBox();
    vector<int> toDelete;
    for(int i=0;i<_bonusMalus.size();i++){
        if(_bonusMalus[i]->getHitBox().intersects(hb_p)){
            _bonusMalus[i]->action(p);
            toDelete.push_back(i);
        }
    }
    for(int i:toDelete)
        _bonusMalus.erase(_bonusMalus.begin()+i);
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
    if(x<0||x>=_matrix.size()||y<0||y>=_matrix[x].size())
        return nullptr;
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

bool Map::canWalk(int x, int y,int type){
    if(x<0||x>=_matrix.size()||y<0||y>=_matrix[x].size())
        return false;
    Bomb * tmp=_bombManager.hasBomb(x,y);
    if(tmp){
        if(tmp->getPersonnage()->getType()!=type || tmp->getPersonnageOut())
            return false;
    }
    return _matrix[x][y]->canWalk();
}
void Map::setCase(sf::Vector2i pos,Case* c){
    _matrix[pos.x][pos.y]=c;
}

void Map::addBonusMalus(BonusMalus * b){
    _bonusMalus.push_back(b);
}

Vector2i Map::getScreenPosition(Vector2i mapPosition)
{
    return pos + Vector2i(mapPosition.x*LARGEUR,mapPosition.y*HAUTEUR);
}

