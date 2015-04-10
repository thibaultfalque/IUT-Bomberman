#ifndef BONUSMALUS_HPP
#define BONUSMALUS_HPP
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

class Personnage;
class BonusMalus : public Drawable
{
    public:
        BonusMalus(Vector2i pos,Vector2i graphicPos,string chm);
        virtual ~BonusMalus();
        virtual void action(Personnage* perso);
        Vector2i getPos();
        FloatRect getHitBox();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        Vector2i _pos;
        Sprite _sprite;
};

#endif // BONUSMALUS_H
