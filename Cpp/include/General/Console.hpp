#include <SFML/Graphics.hpp>
#include <list>

using namespace std;
using namespace sf;



struct dbg_msg
{
    Clock date; //Peut éventuellement servir à mettre une date de péremption au message. (Effacer un message au bout d'un certain temps...). Non implémenté.
    Text msg;
};

class Console
{
private:

    static list<dbg_msg> messages;
    static void deleteOneMessage();
public:
    static void draw(sf::RenderTarget& target, sf::RenderStates states);
    static void say(string message);

};
