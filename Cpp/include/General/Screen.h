#ifndef SCREEN_H
#define SCREEN_H
#include "header.hpp"
using namespace sf;

class Screen:public sf::Drawable
{
    public:
        virtual void onEvent(sf::Event & event);
        virtual void update();
    protected:
        sf::Vector2i* _window_size;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
    private:
};

#endif // SCREEN_H
