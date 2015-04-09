#include "MusicManager.hpp"

MusicManager::MusicManager(const string m)
{

    makeDir("res");
    makeDir("res/config");
    if(!music.openFromFile("res/music/game.ogg")){
        cout<<"erreur chargement musique"<<endl;
    }

    if(!loadFromFile("res/config/music.cfg"))
    {
        Console::say(L"Erreur de chargement du fichier de configuration \n de la musique.",1);
        Console::say(L"La configuration de la musique a été réinitialisée.",1);
        saveConfigurationFile();
    }
    if(_active){
        music.setLoop(true);
        playMusic();
    }
    else
        pause();
}
bool MusicManager::loadFromFile(string file){

        ifstream saveFile(file.c_str(), ios::in);

        if(!saveFile)
            return false;

        string line;
        vector<string> words;

        getline(saveFile, line);
        words = explode(line,':');
        if(words.size()!=2)
            return false;
        music.setVolume(string_to_float(words[1]));

        getline(saveFile, line);
        words = explode(line,':');
        if(words.size()!=2)
            return false;
        changeActive(string_to_bool(words[1]));

        saveFile.close();

        return true;
}

bool MusicManager::saveConfigurationFile(){
     ofstream saveFile("res/config/music.cfg", ios::out | ios::trunc);

     if(!saveFile)
        return false;


    saveFile << "Volume" << ':' << music.getVolume() << endl;
    saveFile << "active" << ':' << _active << endl;

     saveFile.close();

     return true;
}
bool MusicManager::getActive(){
    return _active;
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
    saveConfigurationFile();
}

void MusicManager::setVolume(float volume){
    music.setVolume(volume);
    saveConfigurationFile();
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
    if(!checkbox)
        pause();
    else
        play();
    changeActive(checkbox);
}
float MusicManager::getVolume(){
    return music.getVolume();
}
MusicManager::~MusicManager()
{
    //dtor
}
