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
        Map(string str);
        /** Default destructor */
        virtual ~Map();
        Case* getCase(int x,int y);
        sf::Vector2i& getSize();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        string readFileMap(string str);
        vector<vector<Case*>> _matrix;
        sf::Vector2i _size;

};

#endif // MAP_HPP
