#ifndef BOUTON_HPP
#define BOUTON_HPP

#include "Observateur.hpp"
#include "noClass.hpp"
#include "General.hpp"
#include "header.hpp"

class Bouton:public Observateur
{
    public:
        Bouton(const string text,Vector2f const& taille,Vector2f const& position,string str);
        void onEvent(sf::Event & event);
        void update();
        bool getHover();
        void setAction(string str);
        sf::Vector2f getSize();
        sf::Vector2f getPosition();
        virtual ~Bouton();
    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        void onMouseClick(sf::Event& event);
        void onMouseHover(sf::Event& event);
        sf::Vector2f _size,_pos;
        sf::RectangleShape _rec;
        sf::Text _text;
        string _action;
        Observable obs;
        bool _hover;
};

#endif // BOUTON_HPP
