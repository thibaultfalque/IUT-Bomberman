#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "header.hpp"
#include "General.hpp"
class Background:public sf::Drawable
{
    public:
        Background(string str );
        virtual ~Background();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        string _str;
};

#endif // BACKGROUND_HPP
