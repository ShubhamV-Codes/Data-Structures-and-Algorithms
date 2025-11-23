#include <iostream>
#include <list>
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
};
class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
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
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

Node *splitAtMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    return slow;
}
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL ;
     while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *zigZagLL(Node *head)
{
    Node *rightHead = splitAtMid(head);
    Node *revRightHead = reverse(rightHead);
   
    Node *left = head;
    Node *right = revRightHead;
     Node *tail= right;
    while(left!=NULL && right!=NULL){
        Node *leftNext = left->next ;
        Node *rightNext = right->next;
        left->next = right;
        right->next = leftNext;
        tail= right;
        left = leftNext;
        right =rightNext;

    }
    if(right!=NULL){
        tail->next=right;
    }
    return head;
}
int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.push_back(10);
    ll.push_back(11);
    ll.push_back(12);
    ll.push_back(13);
    ll.push_back(14);
    ll.push_back(15);
    ll.push_back(16);
    
    

    ll.printList();

    ll.head = zigZagLL(ll.head);
    ll.printList();
}