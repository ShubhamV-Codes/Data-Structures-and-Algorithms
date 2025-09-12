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
    Node*temp = head;
    while(temp!=NULL){
     cout<<temp->data << " ";
     temp=temp->next;
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
Node *merge(Node *left, Node *right)
{
    List ans;
    Node *i = left;
    Node *j = right;

    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            ans.push_back(left->data);
            left = left->next;
        }
        else
        {
            ans.push_back(right->data);
            right = right->next;
        }
    }
    while (left != NULL)
    {
        ans.push_back(left->data);
        left = left->next;
    }
    while (right != NULL)
    {
        ans.push_back(right->data);
        right = right->next;
    }
    return ans.head;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *rightHead = splitAtMid(head);
    Node *left = mergeSort(head);
    Node *right = mergeSort(rightHead);

    return merge(left, right);
}

int main()
{
    List ll;
    ll.push_back(132);
    ll.push_back(2);
    ll.push_back(32);
    ll.push_back(4);
    ll.printList();

    ll.head = mergeSort(ll.head);
    ll.printList();
}