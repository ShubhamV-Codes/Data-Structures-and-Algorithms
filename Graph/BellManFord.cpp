#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int v;
    int wt;

    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

<<<<<<< HEAD
void bellManFord(vector<vector<Edge>> & graph , int V, int src){
=======
void bellManFord(vector<vector<Edge>>graph , int V, int src){
>>>>>>> 7d81a27dd777fb6f7d0ee86164e07cd2c8e6a233
    vector<int>dist(V,INT_MAX);
    dist[src] = 0;

    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(Edge e : graph[u]){
<<<<<<< HEAD
                if(dist[u] != INT_MAX && dist[e.v] > dist[u]+e.wt){
=======
                if(dist[e.v] > dist[u]+e.wt){
>>>>>>> 7d81a27dd777fb6f7d0ee86164e07cd2c8e6a233
                    dist[e.v] = dist[u]+e.wt ;
                }
            }
        }
    }
    for(int i: dist){
        cout<<i<<" ";
    }
    cout<<endl;

}

int main(){
    int V = 5;
    vector<vector<Edge>>graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    graph[1].push_back(Edge(2,-4));
    graph[2].push_back(Edge(3,2));
    graph[3].push_back(Edge(4,4));
    graph[4].push_back(Edge(1,-1));
<<<<<<< HEAD
    graph[4].push_back(Edge(0,-4));

    
=======
>>>>>>> 7d81a27dd777fb6f7d0ee86164e07cd2c8e6a233

    bellManFord(graph, 5, 0);
    return 0;
}