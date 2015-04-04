#ifndef IA_HPP
#define IA_HPP

#include "Personnage.hpp"
#include "Graph.hpp"
class IA:public Personnage
{
    public:
        /** Default constructor */
        IA(const sf::Vector2f& position,const string& str,Map & __map,BombManager & bm);
        /** Default destructor */
        virtual ~IA();
        void choiceNewGoal();
        void offenseAction(Graph& g);
        void defenseAction(Graph& g);
        void update();
        virtual void putBomb();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vector2i goal;
        vector<vector<bool>>* _dangerous;
        stack<sf::Vector2i> chemin;
        int _indiceGoal;
};

#endif // IA_HPP
