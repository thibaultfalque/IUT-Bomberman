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
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Text label;
        sf::Sprite sprites[15][15];
        sf::Vector2f position;
        sf::RectangleShape rect;
        bool _hover;
        string file;
        string readFileMap(string str);

};

#endif // VIEWLEVEL_HPP
