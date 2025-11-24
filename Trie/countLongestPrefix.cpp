#include<vector>
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

    void longestHelper(Node* root, string &ans, string temp){
        for(pair<char,Node*> child:root->mp){
           if(child.second->endofStr){
             temp+=child.first;

            if((temp.size()==ans.size() && temp<ans) || (temp.size()>ans.size())){
               ans = temp;
            }
            longestHelper(child.second, ans, temp);
            temp=temp.substr(0,temp.size()-1);
           }
        }
    }
string longestStringPrefix(){
       
    string ans = "";
    longestHelper(root, ans, "");
    return ans;
    }

};

// Longest Word with all prefixes

string longestString(vector<string>dict){
    Trie trie;

    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    return trie.longestStringPrefix();

}

int main(){
    vector<string>dict ={"a","banana","app","appl","ap","apply","apple"};
    cout<<longestString(dict)<<endl;
    return 0;
}
