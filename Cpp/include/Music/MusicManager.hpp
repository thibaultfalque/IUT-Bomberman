#ifndef MUSICMANAGER_HPP
#define MUSICMANAGER_HPP
#include "Observable.hpp"
#include "header.hpp"
#include "General.hpp"
#include "noClass.hpp"
class MusicManager:public Observable
{
    public:
        MusicManager(const string m);
        void playMusic();
        void setVolume(float volume);
        void pause();
        void play();
        void changeActive(bool act);
        virtual void notifyChangeSlider(float volume);
        virtual void notifyChangeCheckbox(bool checkbox);
        bool loadFromFile(std::string file);
        bool saveConfigurationFile();
        bool getActive();
        float getVolume();
        virtual ~MusicManager();
    protected:
    private:
        sf::Music music;
        bool _active;
};

#endif // MUSICMANAGER_HPP
