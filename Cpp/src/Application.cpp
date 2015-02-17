#include "Application.hpp"

Application::Application():_window_size(WINDOW_WIDTH,WINDOW_HEIGHT),
 _window(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), L"Bomberman", Style::Close | Style::Titlebar | Style::Resize),
 _background("backgroundMenu.png")
{
    Menu* m=new Menu(&_window_size);
    ScreenManager::add(m,"Menu");
    ScreenManager::goToScreen("Menu");
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
	_window.draw(_background);
    _window.draw(*ScreenManager::screeCourant);
    Console::draw(_window,RenderStates::Default);
	_window.display();
}
