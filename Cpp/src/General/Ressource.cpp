#include "General.hpp"
#include <iostream>

using namespace std;
using namespace sf;


map<string,Texture> Ressource::textures;
map<string,Font> Ressource::fonts;

Texture & Ressource::getTexture(string src){
    src="res/img/"+src;

    if(textures.find(src)==textures.end()){
        cout << "Chargement de l'image \"" << src << "\" ..." << endl;;
        textures[src]=Texture();
        if(!textures[src].loadFromFile(src)){
            cerr << "Image non trouvée ! " << endl;
        }
    }
    return textures[src];
}
Font & Ressource::getFont(string src){
    src="res/fonts/"+src;

    if(fonts.find(src)==fonts.end()){
        cout << "Chargement de la police \"" << src << "\" ..." << endl;;
        fonts[src]=Font();
        if(!fonts[src].loadFromFile(src)){
            cerr << "Police non trouvée ! " << endl;
            cerr << "La police par defaut sera utilisée." << endl;
            fonts[src]=getFont("defaut.ttf");
        }
    }

    return fonts[src];
}


Sprite Ressource::getSprite(string src,IntRect dim){
    Sprite spt;
    spt.setTexture(Ressource::getTexture(src));
    if(dim.height>0&&dim.width>0)
        spt.setTextureRect(dim);
    return spt;
}
