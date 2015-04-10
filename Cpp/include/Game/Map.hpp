#ifndef MAP_HPP
#define MAP_HPP

#include "header.hpp"
#include "General.hpp"
#include "Case.hpp"
#include "Sol.hpp"
#include "Mur.hpp"
#include "Block.hpp"

class BombManager;

class Map:public sf::Drawable
{
    public:
        /** Default constructor */
        Map(string str,const sf::Vector2i& window_size,BombManager & bm);
        /** Default destructor */
        virtual ~Map();
        void setCase(sf::Vector2i pos,Case* c);
        void checkBonusMalus(Personnage * p);
        Case* getCase(int x,int y);
        Vector2i & getSize();
        Vector2i getMapPosition(Vector2i screenPosition);
        Vector2i getScreenPosition(Vector2i mapPosition);
        bool canWalk(int x, int y, int type=-1);
        sf::Vector2i& getPosition();
        vector<Vector2i>& getPosDepartPerso();
        void addBonusMalus(BonusMalus * b);

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        BombManager & _bombManager;
        string readFileMap(string str);
        vector<vector<Case*>> _matrix;
        sf::Vector2i _size;
        Vector2i pos;
        vector<Vector2i> _posDepartPerso;
        vector<BonusMalus*> _bonusMalus;

};

#endif // MAP_HPP
