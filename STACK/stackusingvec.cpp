#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack{
    vector<T>vec;
    public:
    void push(T val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty "<< " " ;
            return ;
        }
        vec.pop_back();
    }
    T top(){
         if(isEmpty()){
            cout<<"Stack is Empty "<< " " ;
            return -1;
        }
        int idx = vec.size()-1;
        return vec[idx];
    }
    bool isEmpty(){
        return vec.size()==0;
    }
};
int main(){
    Stack <int> S ;
    S.push(3);
    S.push(2);
    S.push(1);

    while(!S.isEmpty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<endl;
    return 0;
}