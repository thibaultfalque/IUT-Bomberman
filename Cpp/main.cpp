
#include "Application.hpp"
using namespace std;
using namespace sf;

int main()
{
   // RenderWindow window(VideoMode(800,600), L"Bomberman", Style::Close | Style::Titlebar | Style::Resize);

    /*while(window.isOpen()){
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
    }*/

    srand(time(NULL));
    Application app;
    app.run();

    return 0;
}
