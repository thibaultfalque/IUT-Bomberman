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
        void offenseAction();
        void defenseAction(Graph& g,vector<vector<bool>>& dangerous);
        void update();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vector2i goal;
};

#endif // IA_HPP
