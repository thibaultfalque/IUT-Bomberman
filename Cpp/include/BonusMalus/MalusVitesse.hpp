#ifndef MALUSVITESSE_HPP
#define MALUSVITESSE_HPP
#include "BonusMalus.hpp"

class MalusVitesse : public BonusMalus
{
    public:
        MalusVitesse();
        virtual ~MalusVitesse();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // MALUSVITESSE_H
