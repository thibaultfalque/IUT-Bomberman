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
    protected:
    private:
};

#endif // STRATBOMBSIMPLE_HPP
