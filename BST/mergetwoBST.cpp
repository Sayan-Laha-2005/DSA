#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL; 
    }
};

//Insert in BST
Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }

    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;

}

Node* buildBST(vector<int> arr) {
    Node* root=NULL;
    for(int val: arr){
        root=insert(root,val);
    }
    return root;
}

Node* buildBSTFromSorted(vector<int> arr,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    Node* curr=new Node(arr[mid]);
    curr->left=buildBSTFromSorted(arr,st,mid-1);
    curr->right=buildBSTFromSorted(arr,mid+1,end);
    return curr;
}

void inorder(Node* root,vector<int>& arr){
    if(root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

Node* mergeBST(Node* root1,Node* root2){
    vector<int> arr1,arr2;
    inorder(root1,arr1);    
    inorder(root2,arr2);

    vector<int> temp;

    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }
        else{
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size()){
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()){
        temp.push_back(arr2[j]);
        j++;
    }
    return buildBSTFromSorted(temp,0,temp.size()-1);  //sorted arr,st idx,end idx
}



int main(){
    vector<int> arr1={8,2,1,10};
    vector<int> arr2={5,3,0};

    Node* root1=buildBST(arr1);
    Node* root2=buildBST(arr2);

    Node* root=mergeBST(root1,root2);
    vector<int> seq;
    inorder(root,seq);
    for(int i:seq){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}