#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
    public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next=NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class HashTable{
    int totalSize;
    int currentSize;
    Node**table;

    int hashFunction( const string &key){
        int idx = 0;
        for(int i=0; i<key.size();i++){
            idx = idx+(key[i]*key[i])%totalSize;
        } 
        return idx%totalSize;  
    }
    void rehash(){
        Node **oldTable = table;
        int oldSize = totalSize;
        totalSize = 2*totalSize;
        table = new Node*[totalSize];

        for(int i = 0; i<totalSize;i++){
            table[i]=NULL;
        }
        for(int i = 0 ;i<oldSize;i++){
            Node *temp=oldTable[i];
            while(temp!=NULL){
                insert(temp->key, temp->val);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }
    }

    public:
    HashTable(int size = 5){
        totalSize= size;
        currentSize = 0;
        table = new Node *[totalSize];

        for(int i=0; i<totalSize; i++){
            table[i]=NULL;
        }

    }

    void insert(string key, int val){
        int idx = hashFunction(key);
        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx]=newNode;
        currentSize++;

        int lambda = currentSize/(double)totalSize;
        if(lambda>1){
            rehash();
        }
        cout<<endl;
    }

    bool exists(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void search(string key){
        
        

    }
    void erase(string key){

    }

    void print(){
        for(int i=0; i<totalSize;i++){
            cout<<"idx"<<i<<"->";
            Node*temp=table[i];
            while(temp!=NULL){
                cout<<temp->key <<"->"<<temp->val << " & ";
                temp=temp->next;
                
            }
            cout<<endl;
        }
    }

};

int main(){
    HashTable ht;

    ht.insert("india", 150);
    ht.insert("usa", 50);
    ht.insert("china", 150);
    ht.insert("nepal", 10);
    ht.insert("bhutan", 50);
    
    ht.print();
    

    return 0;
}