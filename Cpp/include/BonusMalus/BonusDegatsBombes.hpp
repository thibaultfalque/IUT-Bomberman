#ifndef BONUSDEGATSBOMBES_HPP
#define BONUSDEGATSBOMBES_HPP
#include "BonusMalus.hpp"
#include "Personnage.hpp"
class BonusDegatsBombes : public BonusMalus
{
    public:
        BonusDegatsBombes(Vector2i pos,Vector2i graphicPos);
        virtual ~BonusDegatsBombes();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // BONUSDEGATSBOMBES_H
