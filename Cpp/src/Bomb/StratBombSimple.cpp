#include "StratBombSimple.hpp"

StratBombSimple::StratBombSimple()
{
    //ctor
}

StratBombSimple::~StratBombSimple()
{
    //dtor
}
void StratBombSimple::explode(Map& m,Bomb& b){

    rightExplode(m,b);
    leftExplode(m,b);
    downExplode(m,b);
    topExplode(m,b);
}
void StratBombSimple::rightCaseTouch(vector<vector<bool>>& tab,Map& m,Bomb& b){

    sf::Vector2i mapPosition=b.getMapPosition();
    int x=mapPosition.x+1;
    int power=b.getPower();
    bool _continue=true;
    while(power!=0 && _continue){
        if(m.canWalk(x,mapPosition.y)){
            tab[x][mapPosition.y]=true;
            x++;
            power--;
            continue;
        }
        Block* block=dynamic_cast<Block*>(m.getCase(x,mapPosition.y));
        if(block!=nullptr){
            tab[x][mapPosition.y]=true;
        }
        _continue=false;
    }
}
void StratBombSimple::leftCaseTouch(vector<vector<bool>>& tab,Map& m,Bomb& b){

    sf::Vector2i mapPosition=b.getMapPosition();
    int x=mapPosition.x-1;
    int power=b.getPower();
    bool _continue=true;
    while(power!=0 && _continue){
        if(m.canWalk(x,mapPosition.y)){
            tab[x][mapPosition.y]=true;
            x--;
            power--;
            continue;
        }
        Block* block=dynamic_cast<Block*>(m.getCase(x,mapPosition.y));
        if(block!=nullptr){
            tab[x][mapPosition.y]=true;
        }
        _continue=false;
    }
}
void StratBombSimple::downCaseTouch(vector<vector<bool>>& tab,Map& m,Bomb& b){

    sf::Vector2i mapPosition=b.getMapPosition();
    int y=mapPosition.y+1;
    int power=b.getPower();
    bool _continue=true;
    while(power!=0 && _continue){
        if(m.canWalk(mapPosition.x,y)){
            tab[mapPosition.x][y]=true;
            y++;
            power--;

            continue;
        }
        Block* block=dynamic_cast<Block*>(m.getCase(mapPosition.x,y));
        if(block!=nullptr){
            tab[mapPosition.x][y]=true;
        }
        _continue=false;
    }
}
void StratBombSimple::topCaseTouch(vector<vector<bool>>& tab,Map& m,Bomb& b){

    sf::Vector2i mapPosition=b.getMapPosition();
    int y=mapPosition.y-1;
    int power=b.getPower();
    bool _continue=true;
    while(power!=0 && _continue){
        if(m.canWalk(mapPosition.x,y)){
            tab[mapPosition.x][y]=true;
            y--;
            power--;

            continue;
        }
        Block* block=dynamic_cast<Block*>(m.getCase(mapPosition.x,y));
        if(block!=nullptr){
            tab[mapPosition.x][y]=true;
        }
        _continue=false;
    }
}


void StratBombSimple::getCaseTouch(Map& m,vector<vector<bool>>& tab,Bomb& b){

    tab[b.getMapPosition().x][b.getMapPosition().y]=true;
    rightCaseTouch(tab,m,b);
    leftCaseTouch(tab,m,b);
    downCaseTouch(tab,m,b);
    topCaseTouch(tab,m,b);

}


void StratBombSimple::downExplode(Map& m,Bomb& b){
    sf::Vector2i mapPosition=b.getMapPosition();

    int y=mapPosition.y+1;
    int power=b.getPower();
    bool _continue=true;
    while(power!=0 && _continue){
        if(m.canWalk(mapPosition.x,y)){
            y++;
            power--;
            continue;
        }
        Block* block=dynamic_cast<Block*>(m.getCase(mapPosition.x,y));
        if(block!=nullptr){

            sf::Vector2f pos=block->getPosition();
            m.setCase(sf::Vector2i(mapPosition.x,y),new Sol("surfaces/sol.png",true,pos));

        }
        _continue=false;
    }

}
void StratBombSimple::leftExplode(Map& m,Bomb& b){
    sf::Vector2i mapPosition=b.getMapPosition();

    int x=mapPosition.x-1;
    int power=b.getPower();
    bool _continue=true;
    while(power!=0 && _continue){
        if(m.canWalk(x,mapPosition.y)){
            x--;
            power--;
            continue;
        }
        Block* block=dynamic_cast<Block*>(m.getCase(x,mapPosition.y));
        if(block!=nullptr){

            sf::Vector2f pos=block->getPosition();
            m.setCase(sf::Vector2i(x,mapPosition.y),new Sol("surfaces/sol.png",true,pos));

        }
        _continue=false;
    }
}
void StratBombSimple::rightExplode(Map& m,Bomb& b){
    sf::Vector2i mapPosition=b.getMapPosition();

    int x=mapPosition.x+1;
    int power=b.getPower();
    bool _continue=true;
    while(power!=0 && _continue){
        if(m.canWalk(x,mapPosition.y)){
            x++;
            power--;
            continue;
        }
        Block* block=dynamic_cast<Block*>(m.getCase(x,mapPosition.y));
        if(block!=nullptr){

            sf::Vector2f pos=block->getPosition();
            m.setCase(sf::Vector2i(x,mapPosition.y),new Sol("surfaces/sol.png",true,pos));

        }
        _continue=false;
    }
}
void StratBombSimple::topExplode(Map& m,Bomb& b){
    sf::Vector2i mapPosition=b.getMapPosition();

    int y=mapPosition.y-1;
    int power=b.getPower();
    bool _continue=true;
    while(power!=0 && _continue){
        if(m.canWalk(mapPosition.x,y)){
            y--;
            power--;
            continue;
        }
        Block* block=dynamic_cast<Block*>(m.getCase(mapPosition.x,y));

        if(block!=nullptr){

            sf::Vector2f pos=block->getPosition();
            m.setCase(sf::Vector2i(mapPosition.x,y),new Sol("surfaces/sol.png",true,pos));

        }
        _continue=false;
    }
}
