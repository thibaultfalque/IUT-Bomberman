#ifndef MENUOPTION_HPP
#define MENUOPTION_HPP

#include "header.hpp"
#include "Bouton.hpp"
#include "Slider.hpp"
#include "Checkbox.hpp"
#include "Menu.hpp"
#include "MusicManager.hpp"
#include "SoundManager.hpp"
class MenuOption:public Menu
{
    public:
        MenuOption(MusicManager* mm,SoundManager* sm,sf::Vector2i* s);
        virtual ~MenuOption();
    protected:
       // virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:

};

#endif // MENUOPTION_HPP
