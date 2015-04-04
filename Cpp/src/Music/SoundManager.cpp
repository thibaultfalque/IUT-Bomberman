#include "SoundManager.hpp"

SoundManager::SoundManager()
{
    _active=true;
}

void SoundManager::play(const string son){
    if(_active){
        sf::SoundBuffer buffer;
        buffer.loadFromFile("res/sound/"+son);
        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.play();
    }
}

void SoundManager::setVolume(float volume){
    sound.setVolume(volume);
}

void SoundManager::notifyChangeSlider(float volume){
    setVolume(volume);
}
void SoundManager::notifyChangeCheckbox(bool checkbox){
    if(checkbox){
        _active=false;
    }
    else{
        _active=true;
    }
}

SoundManager::~SoundManager()
{
    //dtor
}
