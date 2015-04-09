#include "SoundManager.hpp"

SoundManager::SoundManager()
{
    makeDir("res");
    makeDir("res/config");

    _active=true;

    if(!loadFromFile("res/config/sound.cfg"))
    {
        Console::say(L"Erreur de chargement du fichier de configuration \n des sons.",1);
        Console::say(L"La configuration des sons a été réinitialisée.",1);
        saveConfigurationFile();
    }

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

bool SoundManager::loadFromFile(string file){

        ifstream saveFile(file.c_str(), ios::in);

        if(!saveFile)
            return false;

        string line;
        vector<string> words;

        getline(saveFile, line);
        words = explode(line,':');
        if(words.size()!=2)
            return false;
        setVolume(string_to_float(words[1]));

        getline(saveFile, line);
        words = explode(line,':');
        if(words.size()!=2)
            return false;
        _active=(string_to_bool(words[1]));

        saveFile.close();

        return true;
}

bool SoundManager::saveConfigurationFile(){
     ofstream saveFile("res/config/sound.cfg", ios::out | ios::trunc);

     if(!saveFile)
        return false;

    saveFile<<"volume"<<':'<<sound.getVolume()<<endl;
    saveFile << "active" << ':' << _active << endl;

     saveFile.close();

     return true;
}


void SoundManager::setVolume(float volume){
    sound.setVolume(volume);
    saveConfigurationFile();
}

void SoundManager::notifyChangeSlider(float volume){
    setVolume(volume);
}
void SoundManager::notifyChangeCheckbox(bool checkbox){
    if(!checkbox){
        _active=false;
    }
    else{
        _active=true;
    }
    saveConfigurationFile();
}
bool SoundManager::getActive(){
    return _active;
}
float SoundManager::getVolume(){
    return sound.getVolume();
}
SoundManager::~SoundManager()
{
    //dtor
}
