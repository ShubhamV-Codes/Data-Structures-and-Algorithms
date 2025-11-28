#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Graph{
    int v;
    list<int>*l;
    public:

    Graph(int v ){
        this->v = v;
        l = new list <int>[v];     
    }

    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);


    }
    void print() {
        for (int i = 0; i < v; i++) {
            cout << i << ": ";
            for (int nbr : l[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
       
    }


    void dfshelper(int u , vector<bool>&vis){
        vis[u]=true;
        cout<<u<<" ";
        list<int>neighbors = l[u];
        for(int v:neighbors){
            if(!vis[v]){
                dfshelper(v, vis);
            }
        }
    }
    void dfs (){
        vector<bool> vis(7, false);
        dfshelper( 0,vis);
        cout<<endl;
    }

};

int main (){
    Graph Graph(7);
    Graph.addEdge(0,1);
    Graph.addEdge(0,2);
    Graph.addEdge(1,3);
    Graph.addEdge(2,4);
    Graph.addEdge(3,4);
    Graph.addEdge(3,5);
    Graph.addEdge(4,5);
    Graph.addEdge(5,6);    

    Graph.dfs();
    return 0;


}