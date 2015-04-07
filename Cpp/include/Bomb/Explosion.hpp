#ifndef _EXPLOSION_HPP_
#define _EXPLOSION_HPP_

#include <SFML/Graphics.hpp>
#include <list>
#include "Map.hpp"

class Explosion:public sf::Drawable
{
public:
    Explosion(sf::Vector2i center, int power, int numPerso,Map & _map);
    void update();
    bool getNeedDestroy();
protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    std::list<sf::Sprite> sprites[4];
    int etape;
    sf::Clock _clock;
    bool needDestroy;

};

#endif // _EXPLOSION_HPP_
