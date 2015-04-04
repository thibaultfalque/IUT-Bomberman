#ifndef MUSICMANAGER_HPP
#define MUSICMANAGER_HPP
#include "Observable.hpp"
#include "header.hpp"
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
        virtual ~MusicManager();
    protected:
    private:
        sf::Music music;
        bool _active;
};

#endif // MUSICMANAGER_HPP
