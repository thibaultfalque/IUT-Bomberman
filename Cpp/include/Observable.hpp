#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <vector>
#include <iterator>
#include "Observateur.hpp"

using namespace std;
class Observable
{
    public:
        Observable();

        virtual void notifyChangeSlider(float volume);
        virtual void notifyChangeCheckbox(bool checkbox);
        virtual ~Observable();
    protected:
        vector<Observateur*> obs;
    private:
};

#endif // OBSERVABLE_HPP
