#ifndef EDITEURMAP_HPP
#define EDITEURMAP_HPP

#include "General.hpp"
#include "header.hpp"
#include "Bouton.hpp"
#include "Case.hpp"
#include "Block.hpp"
#include "Sol.hpp"
#include "Mur.hpp"
#include "Humain.hpp"
#include "IA.hpp"

class EditeurMap:public Screen
{
    public:
        /** Default constructor */
        EditeurMap(sf::Vector2i* s);
        /** Default destructor */
        virtual ~EditeurMap();

        void onEvent(sf::Event & event);
        void onMouseClickRight(sf::Event& event);
        void onMouseClickLeft(sf::Event& event);
        void onMouseHover(sf::Event& event);
        void onMouseMove(sf::Event& event);

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
       void save();
       sf::RectangleShape _map;
       sf::RectangleShape _gauche;
       Sprite _block;
       Sprite _mur;
       Sprite _sol;

       Bouton _save;

       vector<Sprite> _perso;
       Sprite* tmp;
       Sprite _spriteTab[15][15];
       char _mapTab[15][15];
       bool _click;
       int id;




};

#endif // EDITEURMAP_HPP
