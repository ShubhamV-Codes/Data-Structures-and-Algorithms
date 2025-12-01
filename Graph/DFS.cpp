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
        vector<bool> vis(v, false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfshelper( i,vis);
            }
        }
       
        cout<<endl;
    }

};

int main (){
    Graph Graph(10);
    Graph.addEdge(0,2);
    Graph.addEdge(2,0);
    Graph.addEdge(2,5);
    Graph.addEdge(5,2);
    Graph.addEdge(1,6);
    Graph.addEdge(6,1);
    Graph.addEdge(6,4);
    Graph.addEdge(4,6); 
    Graph.addEdge(4,3); 
    Graph.addEdge(3,4); 
    Graph.addEdge(4,9);    
    Graph.addEdge(9,4); 
    Graph.addEdge(3,8); 
    Graph.addEdge(8,3); 
    Graph.addEdge(3,7); 
    Graph.addEdge(7,3); 



    Graph.dfs();
    return 0;


}