#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

            // INSERTION IN BST 

Node* insert(Node*root, int val){
    if(root == NULL){
        root= new Node(val);
        return root;
    }
    if(val<root->data){
        root->left= insert(root->left, val);
    }
    else{
        root->right= insert(root->right, val);
    }
    return root;
}

            // BUILD BST

Node* buildBST(int arr[], int n){
    Node*root= NULL;
    for(int i = 0 ; i<n;i++){
        root =insert(root, arr[i]);
    }
    return root; 
}

           //  INORDER TRAVERSAL

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

            //  SEARCH IN BST

bool search(Node*root, int key){
    if(root==NULL)return false;
if(root->data==key)return true;
else if(root->data > key){
    return search(root->left, key);
}
else{
    return search(root->right, key);
}}


          // PRINT IN RANGE

void printInRange(Node*root, int start , int end){
    if(root==NULL)return ;
    if(root->data >= start && root->data <= end){
        printInRange(root->left, start, end);
        cout<<root->data<<" ";
        printInRange(root->right, start, end);
    }
    else if(root->data < start){
        printInRange(root->right, start, end);
    }
    else{
        printInRange(root->left, start, end);
    }
}

        //   ROOT TO LEAF PATH

void rootToLeafPathHelper(Node*root, vector<int>path){
    if(root==NULL)return;
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        for(int i = 0 ; i<path.size();i++){
            cout<<path[i]<<"->";
        }
        cout<<"NULL"<<endl;
    }
    rootToLeafPathHelper(root->left, path);
    rootToLeafPathHelper(root->right, path);
    path.pop_back();
}
void rootToLeafPath(Node*root){
    vector<int>path;
    rootToLeafPathHelper(root , path);

}

                //  VALIDATE BST

bool validateBST(Node*root, Node*min=NULL, Node*max=NULL){
    if(root==NULL)return true;  
    if(min!=NULL && root->data <= min->data) return false;
    if(max!=NULL && root->data >= max->data) return false;
    bool leftValid = validateBST(root->left, min, root);
    bool rightValid = validateBST(root->right, root, max);
    return leftValid && rightValid;
}
bool isValidBST(Node*root){
    return validateBST(root, NULL, NULL);
}

        // MAIN FUNCTION

int main(){
    int arr[] = {5, 1, 3, 4, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = buildBST(arr, n);
    // printInRange(root, 2, 5);
    // cout << endl;

    // rootToLeafPath(root);
  
    if(isValidBST(root)){
        cout<<"Valid BST"<<endl;
    }
    else{
        cout<<"Not a Valid BST"<<endl;
    }
    
}   