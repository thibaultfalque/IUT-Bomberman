#ifndef STRATBOMBSIMPLE_HPP
#define STRATBOMBSIMPLE_HPP
#include "header.hpp"
#include "General.hpp"
#include "Map.hpp"
#include "Case.hpp"
#include "Block.hpp"
#include "Sol.hpp"
class Map;
class StratBombSimple
{
    public:
        /** Default constructor */
        StratBombSimple();
        /** Default destructor */
        virtual ~StratBombSimple();
        void explode(Map& m,sf::Vector2i& pos);
    protected:
    private:
};

#endif // STRATBOMBSIMPLE_HPP
