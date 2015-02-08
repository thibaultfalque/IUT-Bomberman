#ifndef APPLICATION_H
#define APPLICATION_H
#include <SFML/Graphics.hpp>
#include <General.hpp>
#include "header.hpp"

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
};

#endif // APPLICATION_H
