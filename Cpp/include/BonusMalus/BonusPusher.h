#ifndef BONUSPUSHER_H
#define BONUSPUSHER_H
#include "BonusMalus.hpp"
#include "Personnage.hpp"

class BonusPusher : public BonusMalus
{
    public:
        BonusPusher();
        virtual ~BonusPusher();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // BONUSPUSHER_H
