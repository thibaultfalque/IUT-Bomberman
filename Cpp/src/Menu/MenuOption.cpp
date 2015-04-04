#include "MenuOption.hpp"

MenuOption::MenuOption(MusicManager* mm,SoundManager* sm,sf::Vector2i* s):Menu(s)
{
    sf::Vector2f boutonSize(_window_size->x*0.2,_window_size->y*0.1);
    //sf::Vector2f positionor(_window_size->x/2-(boutonSize.x/2),_window_size->y/2-(boutonSize.y/2));
    sf::Vector2f positionValider(_window_size->x/2-(boutonSize.x/2),_window_size->y*0.8);
    sf::Vector2f positionRetour(_window_size->x*0.1,_window_size->y*0.1);
    sf::Vector2f SliderSize(Vector2f(200,10));
    sf::Vector2f SliderSoundPos(_window_size->x/2-(boutonSize.x/2),_window_size->y/2-(boutonSize.y/2)-50);
    sf::Vector2f SliderMusicPos(SliderSoundPos.x,SliderSoundPos.y+50); //+50 ???
    sf::Vector2f CheckboxSoundPos(SliderSoundPos.x-40,SliderSoundPos.y-5);
    sf::Vector2f CheckboxMusicPos(SliderMusicPos.x-40,SliderMusicPos.y-5);


    addObs(new Bouton("Valider",boutonSize,positionValider,"Menu"));
    addObs(new Bouton("Retour",boutonSize,positionRetour,"Menu"));
    addObs(new Slider(mm,0.f, 100.f, 0, SliderSize, SliderSoundPos));
    addObs(new Checkbox(mm,sf::Vector2f(CheckboxSoundPos.x+5,CheckboxSoundPos.y+5),CheckboxSoundPos,sf::Vector2f(10,10),sf::Vector2f(20,20))); // 1 : Position de la marque rouge   2 : Position de la checkbox
    addObs(new Slider(sm,0.f, 100.f, 0, SliderSize, SliderMusicPos));
    addObs(new Checkbox(sm,sf::Vector2f(CheckboxMusicPos.x+5,CheckboxMusicPos.y+5),CheckboxMusicPos,sf::Vector2f(10,10),sf::Vector2f(20,20))); // 1 : Position de la marque rouge   2 : Position de la checkbox
}

MenuOption::~MenuOption()
{
    //dtor
}

