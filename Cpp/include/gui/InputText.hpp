#ifndef INPUTTEXT_HPP
#define INPUTTEXT_HPP

#include "Observateur.hpp"
#include "General.hpp"

class InputText : public Observateur
{
    public:
        InputText(const sf::Vector2f& pos,const sf::Vector2f& taille,const string& str );
        virtual ~InputText();
        void onEvent(sf::Event& event);

        void update();
        string getString();
    protected:
        void onMouseUp(sf::Event& event);
        void onTextEntered(sf::Event& event);
        void onKeyPressed(sf::Event& event);
        void onMouseMove(sf::Event& event);
        void updateCursorPosition();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Text _text;
        string _str;
        unsigned int _cursorPosition;
        sf::Clock _cursorClock;
        sf::Vector2f _size;
        sf::Vector2f _pos;
        sf::RectangleShape _cursor;
        sf::RectangleShape _textArea;

        bool _hover;
        bool _active;
        bool _showCursor;


};

#endif // INPUTTEXT_HPP
