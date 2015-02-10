#ifndef BOUTON_HPP
#define BOUTON_HPP

#include "Observateur.hpp"
#include "noClass/Collision.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "General/Ressource.hpp"
using namespace std;
using namespace sf;
class Bouton:public Observateur
{
    public:
        Bouton(const string text,Vector2f const& taille,Vector2f const& position);
        void onEvent(sf::Event & event);
        void update();
        virtual ~Bouton();
    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vector2f _size,_pos;
        sf::RectangleShape _rec;
        sf::Text _text;
};

#endif // BOUTON_HPP
