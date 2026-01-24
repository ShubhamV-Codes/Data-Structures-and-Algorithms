#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int v;
    vector<vector<pair<int, int>>> adj;
    public:


    Graph(int v ){
        this->v = v;
        adj.resize(v);
    }

    void addEdge(int u , int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});


    }
    void print() {
        for (int i = 0; i < v; i++) {
            cout << i << ": ";
            for (auto &p : adj[i]) {
                cout <<"(" << p.first << ","<< p.second<< ") ";
            }
            cout << endl;
        }
       
    }

};

int main (){
    Graph Graph(5);
    Graph.addEdge(0,1,5);
    Graph.addEdge(1,2,1);
    Graph.addEdge(1,3,3);
    Graph.addEdge(2,3,1);
    Graph.addEdge(2,4,2);

    Graph.print();
    return 0;


}