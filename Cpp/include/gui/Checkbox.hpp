#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include "General.hpp"
#include <header.hpp>
#include <Observable.hpp>
class Checkbox : public Observateur
{
    public:
        Checkbox(Observable* obs,sf::Vector2f posIn,sf::Vector2f posOut, sf::Vector2f sizeIn, sf::Vector2f sizeOut,bool valDepart);
        virtual ~Checkbox();
        void onEvent(sf::Event& event);
        void onMouseClick(sf::Event& event);
        void onMouseHover(sf::Event& event);
        bool isClick();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        bool _hover;
        bool _click;
        sf::RectangleShape _recOut;
        sf::RectangleShape _recIn;
        sf::Vector2f _posRecIn;
        sf::Vector2f _posRecOut;
        sf::Vector2f _sizeRecIn;
        sf::Vector2f _sizeRecOut;
        Observable* _obs;
};

#endif // CHECKBOX_HPP
