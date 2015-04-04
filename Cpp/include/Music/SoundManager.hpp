#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include "Observable.hpp"
#include "header.hpp"

class SoundManager:public Observable
{
    public:
        SoundManager();
        void play(const string son);
        void setVolume(float volume);
        virtual void notifyChangeSlider(float volume);
        virtual void notifyChangeCheckbox(bool checkbox);
        virtual ~SoundManager();
    protected:
    private:
        sf::Sound sound;
        bool _active;
};

#endif // SOUNDMANAGER_H
