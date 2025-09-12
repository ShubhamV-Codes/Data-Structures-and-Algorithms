#include <iostream>
#include <list>
#include <iterator>
using namespace std;

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

void printList(list<int> ll)
{
    // Creating Iterator:-
    list<int>::iterator itr;
    for (itr = ll.begin(); itr != ll.end(); itr++)
    {
        cout << (*itr) << "->";
    }
    cout << " NULL ";
}

int main()
{
    // list<int> ll = {1, 2, 3, 4, 5, 6};

    // Creating List (ll):-
    list<int> ll;

    // Pushing Elements From Front:-
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // Pushing Elements From Back:-
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    // Printing LL;-
    cout << "LL created:- ";
    printList(ll);
    cout << endl;

    // Popping Element from Front:-
    ll.pop_front();
    cout << "Popping from Front :- ";
    printList(ll);
    cout << endl;

    // Popping Element from Back:-
    ll.pop_back();
    cout << "Popping from Back :- ";
    printList(ll);
    cout << endl;

    // Printing Size of LL:-
    cout << "Size of LL:- " << ll.size() << endl;

    // Printing Head and Tail of LL:-
    cout << "Head:- " << ll.front() << "\n";
    cout << "Tail:- " << ll.back() << "\n";

    // inserting Element at Position in LL:-
    int position = 2;
    int value = 7;
    auto it = ll.begin();
    advance(it, position);
    ll.insert(it, value);
    cout << "Inserting Value(7) at 2nd Position:- ";
    printList(ll);

    return 0;
}