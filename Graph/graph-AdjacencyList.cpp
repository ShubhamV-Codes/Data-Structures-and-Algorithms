#include<iostream>
#include<vector>
#include<list>
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

};

int main (){
    Graph Graph(5);
    Graph.addEdge(0,1);
    Graph.addEdge(1,2);
    Graph.addEdge(1,3);
    Graph.addEdge(2,3);
    Graph.addEdge(2,4);

    Graph.print();
    return 0;


}