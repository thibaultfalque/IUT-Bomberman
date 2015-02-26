#ifndef MALUSDEGATSBOMBES_HPP
#define MALUSDEGATSBOMBES_HPP
#include "BonusMalus.hpp"

class MalusDegatsBombes : public BonusMalus
{
    public:
        MalusDegatsBombes();
        virtual ~MalusDegatsBombes();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // MALUSDEGATSBOMBES_H
