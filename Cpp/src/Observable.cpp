#include "Observable.hpp"

Observable::Observable()
{
    //ctor
}

Observable::~Observable()
{
    //dtor
}
void Observable::addObs(Observateur* ob){
    obs.push_back(ob);
}
void Observable::removeObs(Observateur* ob){
}
void Observable::updateObs(){

}
void Observable::notifyChangeSlider(float volume){

}
void Observable::notifyChangeCheckbox(bool checkbox){

}
