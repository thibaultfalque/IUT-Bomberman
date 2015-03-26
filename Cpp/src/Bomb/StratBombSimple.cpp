#include "StratBombSimple.hpp"

StratBombSimple::StratBombSimple()
{
    //ctor
}

StratBombSimple::~StratBombSimple()
{
    //dtor
}
void StratBombSimple::explode(Map& m,sf::Vector2i& pos){
    bool stopDroite=false;
    bool stopGauche=false;
    bool stopHaut=false;
    bool stopBas=false;
    for(int i=0;i<m.getSize().x;i++){
        for(int j=0;j<m.getSize().y;j++){
            if(i==pos.x){
                Case* c=m.getCase(i,j);
                Block* ca = dynamic_cast<Block*>(c);
                Mur* ca2 = dynamic_cast<Mur*>(c);

                if(j<pos.y && !stopHaut){

                    if(ca2!=nullptr ){
                        stopHaut=true;
                    }
                    if(ca!=nullptr  && !stopHaut){
                        m.setCase(sf::Vector2i(i,j),(Case*)new Sol("surfaces/sol.png",true,c->getPosition()));
                        stopHaut=true;
                    }
                }
                else{
                    if(ca2!=nullptr ){
                        stopBas=true;
                    }
                    if(ca!=nullptr  && !stopBas){
                        m.setCase(sf::Vector2i(i,j),(Case*)new Sol("surfaces/sol.png",true,c->getPosition()));
                        cout<<"stop bas" << stopBas<<endl;
                        stopBas=true;
                        cout<<"stop bas" << stopBas<<endl;
                    }
                }

            }

            if(j==pos.y){
                Case* c=m.getCase(i,j);
                Block* ca = dynamic_cast<Block*>(c);
                Mur* ca2 = dynamic_cast<Mur*>(c);

                if(i<pos.x && !stopGauche){

                    if(ca2!=nullptr ){
                        stopGauche=true;
                    }
                    if(ca!=nullptr  && !stopHaut){
                        m.setCase(sf::Vector2i(i,j),(Case*)new Sol("surfaces/sol.png",true,c->getPosition()));
                        stopGauche=true;
                    }
                }
                else{
                    if(ca2!=nullptr ){
                        stopDroite=true;
                    }
                    if(ca!=nullptr  && !stopBas){
                        m.setCase(sf::Vector2i(i,j),(Case*)new Sol("surfaces/sol.png",true,c->getPosition()));
                        cout<<"stop bas" << stopBas<<endl;
                        stopDroite=true;
                        cout<<"stop bas" << stopBas<<endl;
                    }
                }

            }


            /*if(j==pos.y && !stopHorizontal){
                Case* c=m.getCase(i,j);
                Block* ca = dynamic_cast<Block*>(c);
                Mur* ca2 = dynamic_cast<Mur*>(c);
                if(ca2!=nullptr ){
                    stopVertical=true;
                }
                if(ca!=nullptr && !stopVertical){
                    m.setCase(sf::Vector2i(i,j),(Case*)new Sol("surfaces/sol.png",true,c->getPosition()));
                    stopVertical=true;
                }

            }*/

        }
    }
}
