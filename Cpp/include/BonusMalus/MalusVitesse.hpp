#ifndef MALUSVITESSE_HPP
#define MALUSVITESSE_HPP
#include "BonusMalus.hpp"

class MalusVitesse : public BonusMalus
{
    public:
        MalusVitesse(Vector2i pos,Vector2i graphicPos);
        virtual ~MalusVitesse();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // MALUSVITESSE_H
