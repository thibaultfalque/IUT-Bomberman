#include "General.hpp"

using namespace std;
using namespace sf;


list<dbg_msg> Console::messages;
RectangleShape Console::background;

void Console::say(String message,unsigned int categorie){
        Text tmp;
        tmp.setFont(Ressource::getFont("defaut.ttf"));
        tmp.setCharacterSize(13);
        tmp.setString(message);
        switch(categorie){
            case 0:
                tmp.setColor(Color::Green);
            break;
            case 1:
                tmp.setColor(Color::Red);
            break;
            case 2:
                tmp.setColor(Color::White);
            break;

            default:
                tmp.setColor(Color::White);
                categorie = 0;
            break;
        }


        messages.push_back(dbg_msg{Clock(),tmp,categorie});
}



void Console::draw(sf::RenderTarget& target, sf::RenderStates states){
        target.setView(target.getDefaultView());
        int y = target.getView().getSize().y;
        list<dbg_msg>::reverse_iterator it;
        for(it=messages.rbegin();it!=messages.rend();it++){
            y -=it->msg.getGlobalBounds().height + 10;
            it->msg.setPosition(10, y);
        }
        background.setPosition(0,y);
        background.setSize(Vector2f(target.getView().getSize().x/2,target.getView().getSize().y-y));
        background.setFillColor(Color(0,0,0,200));
        background.setOutlineColor(Color(200,200,200));
        background.setOutlineThickness(-2);
        target.draw(background,states);
        for(it=messages.rbegin();it!=messages.rend();it++){
            target.draw(it->msg,states);
        }
}


