#ifndef OBSERVATEUR_HPP
#define OBSERVATEUR_HPP

#include "header.hpp"
class Observateur:public sf::Drawable
{
    public:
        Observateur();
        virtual ~Observateur();
        virtual void update();
        virtual void onEvent(sf::Event& event);
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
    private:
};

#endif // OBSERVATEUR_HPP
