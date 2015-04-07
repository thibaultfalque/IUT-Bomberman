#ifndef IA_HPP
#define IA_HPP

#include "Personnage.hpp"
#include "Graph.hpp"
class IA:public Personnage
{
    public:
        /** Default constructor */
        IA(const sf::Vector2f& position,int numPersonnage,Map & __map,BombManager & bm);
        /** Default destructor */
        virtual ~IA();
        void choiceNewGoal();
        void offenseAction(Graph& g);
        void defenseAction(Graph& g);
        virtual void update();
        virtual void putBomb();
        bool tryPutBomb(Graph& g);
        virtual void onEvent(sf::Event & event);
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vector2i goal;
        vector<vector<bool>>* _dangerous;
        stack<sf::Vector2i> chemin;
        vector<Personnage*> listPersonnage;
};

#endif // IA_HPP
