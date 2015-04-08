#include "Graph.hpp"

Graph::Graph(Map& m,sf::Vector2i posDepart)
{
    bool visited[15][15];
    for(int i=0;i<15;i++)
        for(bool & b:visited[i])
            b=false;
    fillGraph(m,posDepart,visited);

}

Graph::~Graph()
{
    //dtor
}
void Graph::fillGraph(Map& m,sf::Vector2i posDepart,bool visited[15][15]){

    if(visited[posDepart.x][posDepart.y])
        return;
    visited[posDepart.x][posDepart.y]=true;

    if(m.canWalk(posDepart.x+1,posDepart.y)){
        add_edge(posDepart,Vector2i(posDepart.x+1,posDepart.y));
        fillGraph(m,Vector2i(posDepart.x+1,posDepart.y),visited);
    }
    if(m.canWalk(posDepart.x,posDepart.y+1)){
        add_edge(posDepart,Vector2i(posDepart.x,posDepart.y+1));
        fillGraph(m,Vector2i(posDepart.x,posDepart.y+1),visited);
    }
    if(m.canWalk(posDepart.x-1,posDepart.y)){
        add_edge(posDepart,Vector2i(posDepart.x-1,posDepart.y));
        fillGraph(m,Vector2i(posDepart.x-1,posDepart.y),visited);
    }
    if(m.canWalk(posDepart.x,posDepart.y-1)){
        add_edge(posDepart,Vector2i(posDepart.x,posDepart.y-1));
        fillGraph(m,Vector2i(posDepart.x,posDepart.y-1),visited);
    }
}
void Graph::add_edge(sf::Vector2i indice,sf::Vector2i neightboor){

    if(indice.x<0 || indice.x>=15 || indice.y<0 || indice.y>=15)
        return;
    _graph[indice.x][indice.y].push_front(neightboor);
}
sf::Vector2i& Graph::breadFirstSearch(const sf::Vector2i& src,vector<vector<bool>>& dangerous,Map& m){
    sf::Vector2i coordCaseSecure;
    color.resize(15);
    dist.resize(15);
    parent.resize(15);
    for(int i = 0; i < 15; ++i){
        for(int j = 0; j < 15; ++j){
            color[i].push_back(WHITE);
            dist[i].push_back(INF);
            parent[i].push_back(NUL);
        }
    }
    color[src.x][src.y]=GREY;
    dist[src.x][src.y]=0;
    parent[src.x][src.y]=NUL;
    queue<sf::Vector2i> q;
    q.push(src);
    bool havefind=false;
    while(!q.empty()){
        sf::Vector2i u=q.front();
        q.pop();
        for(list<sf::Vector2i>::iterator it=_graph[u.x][u.y].begin();it!=_graph[u.x][u.y].end();++it){
            sf::Vector2i v=*it;
            if(color[v.x][v.y]==WHITE){

                if(!havefind && !dangerous[v.x][v.y] && m.canWalk(v.x,v.y)){
                    coordCaseSecure=sf::Vector2i(v.x,v.y);
                    havefind=true;
                }
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
void Graph::getPath(sf::Vector2i& src,sf::Vector2i& dest,stack<sf::Vector2i>& chemin){
    Vector2i tmp;
    while(!chemin.empty()){
        tmp=chemin.top();
        chemin.pop();
    }
    while(src!=dest && parent[dest.x][dest.y]!=NUL){;
        chemin.push(dest);
        dest=parent[dest.x][dest.y];
    }
    if(src!=dest){
        while(!chemin.empty())
            chemin.pop();
    }
    chemin.push(src);


}
