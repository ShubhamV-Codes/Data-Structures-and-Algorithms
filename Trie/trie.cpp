#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> mp;
    bool endofStr;
    Node()
    {
        endofStr = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    // INSERT FUNCTION

    void insert(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->mp.count(key[i]) == 0)
            {
                temp->mp[key[i]] = new Node();
            }
            temp = temp->mp[key[i]];
        }
        temp->endofStr = true;
    }

    // SEARCH FUNCTION 

    bool search(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->mp.count(key[i]))
            {
                temp = temp->mp[key[i]];
            }else{
                return false;
            }
        }
        return temp->endofStr;
    }


};

int main(){
    Trie trie;
    trie.insert("shubham");
    trie.insert("shubhangi");
    trie.insert("shradhha");

     if(trie.search("shradhha")){
        cout<<"value got in TRIE" << endl;
     }else{
        cout << "Searched Value is not available in TRIE" <<endl;
     }
}
