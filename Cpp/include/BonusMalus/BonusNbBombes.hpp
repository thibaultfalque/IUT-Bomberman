#ifndef BONUSNBBOMBES_HPP
#define BONUSNBBOMBES_HPP
#include "BonusMalus.hpp"
#include "Personnage.hpp"

class BonusNbBombes : public BonusMalus
{
    public:
        BonusNbBombes(Vector2i pos,Vector2i graphicPos);
        virtual ~BonusNbBombes();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // BONUSNBBOMBES_H
