#ifndef STRATBOMBSIMPLE_HPP
#define STRATBOMBSIMPLE_HPP
#include "header.hpp"
#include "General.hpp"
#include "Map.hpp"
#include "Case.hpp"
#include "Block.hpp"
#include "Sol.hpp"
#include "Bomb.hpp"
class Bomb;
class Map;
class StratBombSimple
{
    public:
        /** Default constructor */
        StratBombSimple();
        /** Default destructor */
        virtual ~StratBombSimple();
        void explode(Map& m,Bomb& bomb);
       void getCaseTouch(Map& m,vector<vector<bool>>& tab,Bomb& b);
    protected:
    private:
        void rightExplode(Map& m,Bomb& bomb);
        void leftExplode(Map& m,Bomb& bomb);
        void topExplode(Map& m,Bomb& bomb);
        void downExplode(Map& m,Bomb& bomb);

        void rightCaseTouch(vector<vector<bool>>& tab,Map& m,Bomb& b);
        void leftCaseTouch(vector<vector<bool>>& tab,Map& m,Bomb& b);
        void downCaseTouch(vector<vector<bool>>& tab,Map& m,Bomb& b);
        void topCaseTouch(vector<vector<bool>>& tab,Map& m,Bomb& b);

};

#endif // STRATBOMBSIMPLE_HPP
