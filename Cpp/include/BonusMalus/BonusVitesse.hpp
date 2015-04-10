#ifndef BONUSVITESSE_HPP
#define BONUSVITESSE_HPP
#include "BonusMalus.hpp"

class BonusVitesse : public BonusMalus
{
    public:
        BonusVitesse(Vector2i pos,Vector2i graphicPos);
        virtual ~BonusVitesse();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // BONUSVITESSE_H
