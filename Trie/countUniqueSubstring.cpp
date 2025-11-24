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

    // Node Counter Function

    int countNodeHelper(Node* root){
        int ans = 0;
        for(pair<char,Node*>child:root->mp){
            ans+=countNodeHelper(child.second);
        }
        return ans+1;
    }
    int countNodes(){
        return countNodeHelper(root);
    }

};

 // Count Unique 

int countUnique(string str){
    Trie trie;

    for(int i=0;i<str.size();i++){
        string suffix = str.substr(i);
        trie.insert(suffix);
    }
    return trie.countNodes();
}

int main(){
    string str = "abc";
    cout << countUnique(str) << endl;
    return 0;
}
