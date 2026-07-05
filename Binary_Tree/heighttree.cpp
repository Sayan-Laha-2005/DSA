#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

static int idx=-1;

Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx]==-1){
        return NULL;
    }

    Node* root=new Node(preorder[idx]);
    root->left=buildTree(preorder);
    root->right=buildTree(preorder);

    return root;

}

//height of tree

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    return max(leftHeight,rightHeight)+1;
}

//count of nodes in tree    

int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftCount=countNodes(root->left);
    int rightCount=countNodes(root->right);

    return leftCount+rightCount+1;
}

//sum of nodes in tree

int sumNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftSum=sumNodes(root->left);
    int rightSum=sumNodes(root->right);

    return leftSum+rightSum+root->data;
}

int main(){

    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1,};

    Node* root=buildTree(preorder);
    //cout<<"Count of nodes in the tree is: "<<countNodes(root)<<endl;
    //cout<<"Height of the tree is: "<<height(root)<<endl;
    cout<<"Sum of nodes in the tree is: "<<sumNodes(root)<<endl;

    return 0;
}