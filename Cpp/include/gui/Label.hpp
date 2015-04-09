#ifndef LABEL_HPP
#define LABEL_HPP

#include "header.hpp"
#include "General.hpp"
#include "Observateur.hpp"
class Label:public Observateur
{
    public:
        /** Default constructor */
        Label(sf::String str,sf::Vector2f position,float tailleCharacter,const sf::Color& color);
        /** Default destructor */
        virtual ~Label();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Text _text;

};

#endif // LABEL_HPP
