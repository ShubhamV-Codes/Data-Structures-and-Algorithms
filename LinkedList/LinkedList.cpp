#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next=nullptr;
    }
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head=nullptr;
    }

    // We need Destructor for preventing memory from leak 
    ~LinkedList(){
        Node* current = head;
        while(current){
            Node*nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;  
    }
    
    void print(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"->";    
            temp = temp->next;
        }
        cout<<"nullptr";

    }
};


int main(){
    LinkedList ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);
    ll.print();
    return 0;
}