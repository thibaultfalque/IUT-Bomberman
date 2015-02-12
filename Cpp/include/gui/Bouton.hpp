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
        void setAction(string str);
        virtual ~Bouton();
    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vector2f _size,_pos;
        sf::RectangleShape _rec;
        sf::Text _text;
        string _action;
};

#endif // BOUTON_HPP
