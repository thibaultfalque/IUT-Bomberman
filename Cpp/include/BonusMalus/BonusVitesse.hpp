#ifndef BONUSVITESSE_HPP
#define BONUSVITESSE_HPP
#include "BonusMalus.hpp"

class BonusVitesse : public BonusMalus
{
    public:
        BonusVitesse();
        virtual ~BonusVitesse();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // BONUSVITESSE_H
