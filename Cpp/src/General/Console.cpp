#include "General.hpp"

using namespace std;
using namespace sf;


list<dbg_msg> Console::messages;

void Console::say(string message){
        Text tmp;
        tmp.setFont(Ressource::getFont("defaut.ttf"));
        tmp.setCharacterSize(13);
        tmp.setString(message);
        tmp.setColor(Color::White);
        messages.push_back(dbg_msg{Clock(),tmp});
}



void Console::draw(sf::RenderTarget& target, sf::RenderStates states){
        target.setView(target.getDefaultView());
        int y = target.getView().getSize().y;
        list<dbg_msg>::reverse_iterator it;
        int cmp=0;
        for(it=messages.rbegin();it!=messages.rend();it++){
            y -=it->msg.getGlobalBounds().height + 10;
            it->msg.setPosition(10, y);
            target.draw(it->msg,states);
        }
}


