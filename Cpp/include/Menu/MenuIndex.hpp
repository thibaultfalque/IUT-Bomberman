#ifndef MENUINDEX_HPP
#define MENUINDEX_HPP

#include <Menu.hpp>
#include <Slider.hpp>

class MenuIndex : public Menu
{
    public:
        MenuIndex(sf::Vector2i* s);
        virtual ~MenuIndex();
    protected:
        //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
};

#endif // MENUINDEX_HPP
