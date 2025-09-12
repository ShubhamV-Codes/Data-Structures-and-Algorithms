#include <iostream>
#include <iterator>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
    // ~Node(){
    //     if(next!=NULL){
    //            cout << "Deleting node with data: " << data << endl;
    //         delete next;
    //         next = NULL ;
    //     }
    // }
};
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    //  ~List() {
    //     Node* current = head;
    //     while (current != NULL) {
    //          cout << "Deleting node with data: " << current->data << endl;
    //         Node* nextNode = current->next;
    //         delete current;
    //         current = nextNode;
    //     }
    //     head = tail = NULL;
    // }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val)
    {
        Node *Back = new Node(val);
        if (head == NULL)
        {
            head = tail = Back;
        }
        else
        {
            tail->next = Back;
            tail = Back;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }
    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Location\n";
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "LL is empty\n";
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            // List is empty
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == NULL)
        {
            // Only one node
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        tail = temp;
    }
    Node * reverse(){
        Node * curr = head;
        Node * prev=NULL;
        Node *next = NULL;
        while(curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr= next;
        
        }   
        head = prev;
        return head;
     }
};
int main()
{
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList(); // printing after pushing elements from front

    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.printList(); // printing after pushing elements from back

    ll.insert(100, 2);
    ll.insert(200, 3);
    ll.insert(300, 4);
    ll.printList(); // printing after pushing elements at 2nd, 3rd, 4th Position

    // Destructor ~List() automatically called here and delete memory of nodes

    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.printList(); // printing after popping from front

    ll.pop_back();
    ll.pop_back();
    ll.pop_back();
    ll.printList(); // printing after popping from back

    ll.reverse();
    ll.printList();

    return 0;
}