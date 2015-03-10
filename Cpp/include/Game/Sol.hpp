#ifndef SOL_HPP
#define SOL_HPP

#include "Case.hpp"
#include "BonusMalus.hpp"
class Sol:public Case
{
    public:
        /** Default constructor */
        Sol(string str,bool b,sf::Vector2f pos);
        /** Default destructor */
        virtual ~Sol();
        void setBonusMalus(BonusMalus* bm);
        BonusMalus* getBonusMalus();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        BonusMalus* _bonusMalus;
};

#endif // SOL_HPP
