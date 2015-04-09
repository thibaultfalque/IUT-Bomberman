#ifndef APPLICATION_H
#define APPLICATION_H
#include <SFML/Graphics.hpp>
#include <General.hpp>
#include "header.hpp"
#include "Menu.hpp"
#include "Background.h"
#include "MenuIndex.hpp"
#include "MenuOption.hpp"
#include "MenuOptionTouch.hpp"
#include "Game.hpp"
#include "Editeur/EditeurMap.hpp"
#include "MusicManager.hpp"
#include "SoundManager.hpp"
#include "MenuPause.hpp"
#include "MenuChoixGame.hpp"
class Application
{
    public:
        Application();
        virtual ~Application();
        void run();
    protected:
        void processEvents();
        void update();
        void render();
    private:
        sf::Vector2i _window_size;
        sf::RenderWindow _window;
        sf::ContextSettings _window_setting;
        EventManager _eventManager;
        bool _showConsole;
        sf::Clock _clock;
        sf::Time tps;
};

#endif // APPLICATION_H
