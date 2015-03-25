#include "Application.hpp"

Application::Application():_window_size(WINDOW_WIDTH,WINDOW_HEIGHT),
 _window(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), L"Bomberman", Style::Close | Style::Titlebar | Style::Resize)

{
    _showConsole=false;

    MenuIndex* m=new MenuIndex(&_window_size);
    ScreenManager::add(m,"Menu");
    ScreenManager::goToScreen("Menu");

    Game* g=new Game(&_window_size);
    ScreenManager::add(g,"Game");


    EditeurMap* e=new EditeurMap(&_window_size);
    ScreenManager::add(e,"Editeur");


}

Application::~Application()
{
    //dtor
}
void Application::run(){
    while (_window.isOpen())
	{
		processEvents();
		update();
		render();

	}
}
void Application::processEvents()
{
    Event event;
	while (_window.pollEvent(event))
	{

		switch(event.type)
		{
            case Event::Closed:
                _window.close();

            break;
            case sf::Event::KeyReleased:
                if(event.key.code == sf::Keyboard::F1){
                    _showConsole=!_showConsole;
                }
            break;
            default:
                ScreenManager::screeCourant->onEvent(event);
            break;
		} //SWITCH
	}
}


void Application::update()
{

    //_background.update();
    ScreenManager::screeCourant->update();
    //_audio.update();
}

void Application::render()
{
	_window.clear();

    _window.draw(*ScreenManager::screeCourant);
    if(_showConsole)
        Console::draw(_window,RenderStates::Default);
	_window.display();
}
