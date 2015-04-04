#include "MusicManager.hpp"

MusicManager::MusicManager(const string m)
{
    _active=true;
    playMusic();
}

void MusicManager::playMusic(){
    if(_active){
        music.stop();
        if(!music.openFromFile("res/music/game.ogg")){
        cout<<"erreur chargement musique"<<endl;
        }
        music.play();
        music.setVolume(50.0);
    }
}

void MusicManager::changeActive(bool act){
    _active=act;
}

void MusicManager::setVolume(float volume){
    music.setVolume(volume);
}

void MusicManager::pause(){
    music.pause();
}

void MusicManager::play(){
    music.play();
}
void MusicManager::notifyChangeSlider(float volume){
    setVolume(volume);
}
void MusicManager::notifyChangeCheckbox(bool checkbox){
    if(checkbox)
        pause();
    else
        play();
    changeActive(!checkbox);
}
MusicManager::~MusicManager()
{
    //dtor
}
