#ifndef BONUSMALUS_HPP
#define BONUSMALUS_HPP

class Personnage;
class BonusMalus
{
    public:
        BonusMalus();
        virtual ~BonusMalus();
        virtual void action(Personnage* perso);
    protected:
    private:
};

#endif // BONUSMALUS_H
