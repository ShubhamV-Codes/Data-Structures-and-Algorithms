#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectNRopes(vector<int>ropes){
    priority_queue<int,vector<int>,greater<int>>PQ(ropes.begin(),ropes.end());
    int cost = 0 ;
    while(PQ.size()>1){
        int min1= PQ.top();
        PQ.pop();
        int min2 = PQ.top();
        PQ.pop();
        cost += min1+min2;
        PQ.push(min1+min2);
    }
    cout<<"Min Cost:"<<cost <<endl;
    return cost;
}

int main(){
    vector<int>ropes={4,3,2,6};
    connectNRopes(ropes);
    
    return 0;
}