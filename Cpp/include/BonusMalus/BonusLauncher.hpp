#ifndef BONUSLAUNCHER_H
#define BONUSLAUNCHER_H
#include "BonusMalus.hpp"
#include "Personnage.hpp"

class BonusLauncher : public BonusMalus
{
    public:
        BonusLauncher();
        virtual ~BonusLauncher();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // BONUSLAUNCHER_H
