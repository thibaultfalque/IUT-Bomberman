#include "Application.hpp"

Application::Application():_window_size(WINDOW_WIDTH,WINDOW_HEIGHT),
 _window(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), L"Bomberman", Style::Close | Style::Titlebar | Style::Resize)

{
    _showConsole=false;

    MenuIndex* m=new MenuIndex(&_window_size);
    ScreenManager::add(m,"Menu");
    ScreenManager::goToScreen("Menu");

    Game* g=new Game(&_window_size,_eventManager);
    ScreenManager::add(g,"Game");


    EditeurMap* e=new EditeurMap(&_window_size);
    ScreenManager::add(e,"Editeur");

    MusicManager* musique=new MusicManager("02-opening.ogg");
    SoundManager* son=new SoundManager();

    MenuOption* mo=new MenuOption(musique,son, &_window_size);
    ScreenManager::add(mo,"Options");

    MenuOptionTouch* mot=new MenuOptionTouch(&_window_size,_eventManager);
    ScreenManager::add(mot,"OptionsTouches");


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
                if(event.key.code == _eventManager.getEventKey("Aff/Cach Console")){
                    _showConsole=!_showConsole;
                }
                ScreenManager::screeCourant->onEvent(event);
            break;
            default:
                ScreenManager::screeCourant->onEvent(event);
            break;
		} //SWITCH
	}
}


void Application::update()
{
    tps=_clock.getElapsedTime();
    //_background.update();
    ScreenManager::screeCourant->update(tps);
    _clock.restart();
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
