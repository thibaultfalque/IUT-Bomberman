#include "Graph.hpp"

Graph::Graph(Map& m,sf::Vector2i posDepart)
{
    cout<<"fill gauche"<<endl;
    fillGraph(m,posDepart,sf::Vector2i(posDepart.x-1,posDepart.y));
    cout<<"fill droite"<<endl;
    fillGraph(m,posDepart,sf::Vector2i(posDepart.x+1,posDepart.y));
    cout<<"fill haut"<<endl;
    fillGraph(m,posDepart,sf::Vector2i(posDepart.x,posDepart.y-1));
    cout<<"fill bas"<<endl;
    fillGraph(m,posDepart,sf::Vector2i(posDepart.x,posDepart.y+1));
    cout<<"fill end"<<endl;
}

Graph::~Graph()
{
    //dtor
}
void Graph::fillGraph(Map& m,sf::Vector2i& posDepart,sf::Vector2i posEnd){
    if(!m.canWalk(posEnd.x,posEnd.y) || !_graph[posEnd.x][posEnd.y].empty() || posDepart.x<0 || posDepart.x>=15 || posDepart.y<0 || posDepart.y>=15 || posEnd.y<0 || posEnd.y>=15 || posEnd.x<0 || posEnd.x>=15)
        return;
    add_edge(posDepart,posEnd);
    cout<<"depart "<<posDepart.x<<" "<<posDepart.y<<" end "<<posEnd.x<<" "<<posEnd.y<<endl;
    fillGraph(m,posEnd,sf::Vector2i(posEnd.x-1,posEnd.y));
    fillGraph(m,posEnd,sf::Vector2i(posEnd.x+1,posEnd.y));
    fillGraph(m,posEnd,sf::Vector2i(posEnd.x,posEnd.y-1));
    fillGraph(m,posEnd,sf::Vector2i(posEnd.x,posEnd.y+1));
}
void Graph::add_edge(sf::Vector2i& indice,sf::Vector2i& neightboor){

    if(indice.x<0 || indice.x>=15 || indice.y<0 || indice.y>=15)
        return;
    //cout<<"add"<<endl;
    _graph[indice.x][indice.y].push_front(neightboor);
}
sf::Vector2i& Graph::breadFirstSearch(const sf::Vector2i& src,vector<vector<bool>>& dangerous){
    sf::Vector2i coordCaseSecure;
    color.resize(15);
    dist.resize(15);
    parent.resize(15);
    for(int i = 0; i < 15; ++i){
        for(int j = 0; j < 15; ++j){
            cout<<"i "<<i<<" j "<<j<<endl;
            color[i].push_back(WHITE);
            dist[i].push_back(INF);
            parent[i].push_back(NUL);
        }
    }
    cout<<"init"<<endl;
    color[src.x][src.y]=GREY;
    dist[src.x][src.y]=0;
    parent[src.x][src.y]=NUL;
    queue<sf::Vector2i> q;
    q.push(src);
    while(!q.empty()){
        sf::Vector2i u=q.front();
        q.pop();
        for(list<sf::Vector2i>::iterator it=_graph[u.x][u.y].begin();it!=_graph[u.x][u.y].end();++it){
            sf::Vector2i v=*it;
            if(!dangerous[v.x][v.y])
                coordCaseSecure=sf::Vector2i(v.x,v.y);
            if(color[v.x][v.y]==WHITE){
                dist[v.x][v.y]=dist[u.x][u.y]+1;
                color[v.x][v.y]=GREY;
                parent[v.x][v.y]=u;
                q.push(v);
            }
        }
        color[u.x][u.y]=BLACK;
    }
    return coordCaseSecure;
}
