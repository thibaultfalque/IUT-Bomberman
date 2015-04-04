#ifndef SLIDER_HPP
#define SLIDER_HPP

#include <Observateur.hpp>
#include <Observable.hpp>
#include <header.hpp>


class Slider : public Observateur
{
    public:
        Slider(Observable* obs,const float& valMin, const float& valMax,const float& val,const sf::Vector2f& taille, const sf::Vector2f& pos);
        virtual ~Slider();
        void onEvent(sf::Event& event);
        void onMouseClick(Event& event);
        void onMouseHover(Event& event);
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vector2f _size;
        sf::Vector2f _pos;
        sf::Vector2f _positionSouris;
        sf::RectangleShape _bar;
        sf::RectangleShape _cursor;
        Observable* _obs;
        float _valMin;
        float _valMax;
        float _currentValue;
        bool _isHover;
};

#endif // SLIDER_HPP
