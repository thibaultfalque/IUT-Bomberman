#ifndef MALUSNBBOMBES_HPP
#define MALUSNBBOMBES_HPP
#include "BonusMalus.hpp"

class MalusNbBombes : public BonusMalus
{
    public:
        MalusNbBombes(Vector2i pos,Vector2i graphicPos);
        virtual ~MalusNbBombes();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // MALUSNBBOMBES_H
