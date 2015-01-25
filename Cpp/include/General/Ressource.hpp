#ifndef _RESSOURCE_HPP_
#define _RESSOURCE_HPP_


#include <SFML/Graphics.hpp>
#include <map>

using namespace std;
using namespace sf;

class Ressource{
    private:
        static map<string,Texture> textures;
        static map<string,Font> fonts;

    public:
        static Texture & getTexture(string src);
        static Font & getFont(string src);
        static Sprite getSprite(string src,IntRect dim=IntRect(0,0,0,0));

};

#endif // _RESSOURCE_HPP_
