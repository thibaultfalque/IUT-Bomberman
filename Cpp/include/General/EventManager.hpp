#ifndef _EVENTMANAGER_HPP_
#define _EVENTMANAGER_HPP_
#include <map>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

typedef  std::map<std::string,sf::Keyboard::Key> EventConf;


class EventManager
{

protected:

    static const std::string KeyName[];


    EventConf _eventconf;
    bool loadFromFile(std::string file);
    bool saveConfigurationFile();
    void initDefault();

public:
    EventManager();

    void addEventConf(std::string str,sf::Keyboard::Key key);


    bool getEventState(std::string str);

    EventConf& getListKey();

    sf::Keyboard::Key getEventKey(std::string str);

    static std::string keyToString(sf::Keyboard::Key key);


};
#endif
