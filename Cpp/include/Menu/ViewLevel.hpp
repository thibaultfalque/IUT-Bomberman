#ifndef VIEWLEVEL_HPP
#define VIEWLEVEL_HPP

#include "header.hpp"
#include "General.hpp"
class ViewLevel:public sf::Drawable
{
    public:
        /** Default constructor */
        ViewLevel(string file,sf::Vector2f pos);
        /** Default destructor */
        virtual ~ViewLevel();
        void onEvent(sf::Event & event);
        void update(sf::Time& tps);
        string getNameFile();
        bool isClick();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Text label;
        sf::Sprite sprites[15][15];
        sf::Vector2f position;
        sf::RectangleShape rect;
        sf::Vector2f _size;
        bool _hover;
        bool _click;
        string file;
        string readFileMap(string str);

        void onMouseHover(sf::Event& event);
        void onMouseClick(sf::Event& event);

};

#endif // VIEWLEVEL_HPP
