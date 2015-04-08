#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Map.hpp"
#include "header.hpp"
#include<list>
#include<queue>
enum{WHITE,GREY,BLACK};
const int INF= 2147483647;
const sf::Vector2i NUL=sf::Vector2i(-1,-1);

class Graph
{
    public:
        /** Default constructor */
        Graph(Map& m,sf::Vector2i posDepart);
        /** Default destructor */
        virtual ~Graph();
        void add_edge(sf::Vector2i indice,sf::Vector2i neightboor);
        sf::Vector2i& breadFirstSearch(const sf::Vector2i& src,vector<vector<bool>>& dangerous,Map& m);
        void getPath(sf::Vector2i& src,sf::Vector2i& dest,stack<sf::Vector2i>& chemin);
    protected:
    private:
        void fillGraph(Map& m,sf::Vector2i posDepart,bool visited[15][15]);
        list<sf::Vector2i> _graph[15][15];
        vector<vector<int>> color;
        vector<vector<sf::Vector2i>> parent;
        vector<vector<int>> dist;
};

#endif // GRAPH_HPP
