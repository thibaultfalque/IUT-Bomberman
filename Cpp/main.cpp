
#include <SFML/Graphics.hpp>
#include "General.hpp"
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800,600), L"Bomberman", Style::Close | Style::Titlebar | Style::Resize);
    Console::say("SALUT1");
    Console::say("SALUT2");
    Console::say("SALUT3");
    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            switch(e.type){
                case Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        Console::draw(window, RenderStates::Default );
        window.display();
    }
    return 0;
}
