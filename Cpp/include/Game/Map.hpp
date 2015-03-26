#ifndef MAP_HPP
#define MAP_HPP

#include "header.hpp"
#include "General.hpp"
#include "Case.hpp"
#include "Sol.hpp"
#include "Mur.hpp"
#include "Block.hpp"

class Map:public sf::Drawable
{
    public:
        /** Default constructor */
        Map(string str,const sf::Vector2i& window_size);
        /** Default destructor */
        virtual ~Map();
        void setCase(sf::Vector2i pos,Case* c);
        Case* getCase(int x,int y);
        Vector2i & getSize();
        Vector2i getMapPosition(Vector2i screenPosition);
        bool canWalk(int x, int y);
        sf::Vector2i& getPosition();

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        string readFileMap(string str);
        vector<vector<Case*>> _matrix;
        sf::Vector2i _size;
        Vector2i pos;

};

#endif // MAP_HPP
