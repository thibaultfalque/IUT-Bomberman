#ifndef CASE_HPP
#define CASE_HPP

#define MUR 0
#define BLOCK 1
#define SOL 2

#define LARGEUR 38
#define HAUTEUR 38

#include "header.hpp"
#include "General.hpp"
class Case:public sf::Drawable
{
    public:
        /** Default constructor */
        Case(string str,bool b,sf::Vector2f pos);
        /** Default destructor */
        virtual ~Case();
        void setPosition(const sf::Vector2f& pos);
        bool canWalk();
        void setCanWalk(bool b);
    protected:
        sf::Sprite _sprite;
        bool _canWalk;
        sf::Vector2f _pos;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        string _str;

};

#endif // CASE_HPP
