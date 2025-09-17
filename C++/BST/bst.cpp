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

void inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

        // PREORDER TRAVERSAL

void preOrder(Node* root){
    if(root == NULL) return;
     cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}        

        // POSTORDER TRAVERSAL
  
void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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
    }
}


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

            // Build BST From Sorted Array (With Min. Height)


Node* buildBSTfromSorted(int arr[],int st, int end ){
    if(st>end){
        return NULL;
    }
    int mid = st+(end-st)/2;
    Node* curr= new Node (arr[mid]);
    curr->left=buildBSTfromSorted(arr, st, mid-1);
    curr->right=buildBSTfromSorted(arr,mid+1,end);
    return curr;
}

             // CONVERT BST INTO BALANCED BST
    void getInOrder(Node*root, vector<int>& nodes){
        if(root==NULL)return ;
        getInOrder(root->left, nodes);
        nodes.push_back(root->data);
        getInOrder(root->right, nodes);
    }
    Node* BSTfromSortedVector(const vector<int>& arr, int st, int end){
        if(st>end){
            return NULL;
        }
        int mid=st+(end-st)/2;
        Node*curr = new Node(arr[mid]);
        curr->left=BSTfromSortedVector(arr,st,mid-1);
        curr->right=BSTfromSortedVector(arr,mid+1,end);
        return curr;
    }
    Node* BalancedBST(Node* root){
        vector<int>nodes;
        getInOrder(root, nodes);
        return BSTfromSortedVector(nodes, 0, nodes.size()-1);
    }         
             


        // MAIN FUNCTION

int main(){
    int arr[] = {3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
   Node*root= buildBSTfromSorted(arr,0,n-1);

// Node * root = new Node(6);
// root->left =new Node(5);
// root->left->left = new Node(4);
// root->left->left->left=new Node(3);

// root->right = new Node(7);
// root->right->right= new Node(8);
// root->right->right->right=new Node(9);

//   root= BalancedBST(root);
 cout<<" PreOrder :  ";
   preOrder(root);
   cout<<endl;
   cout<<" InOrder :   ";
   inOrder(root);
   cout<<endl;
   cout<<" PostOrder : ";
postOrder(root);
   cout<<endl;
    
    return 0;
} 
/*
If you see 'M' next to bst.cpp in git status, it means the file has been modified but not yet committed. To update git, use:
    git add bst.cpp
    git commit -m "Update bst.cpp"
*/
