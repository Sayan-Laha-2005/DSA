#include<iostream>
#include<vector>
#include<queue>
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

//preorder traversal

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//inorder traversal

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//postorder traversal

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//level order traversal

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);

    while(q.size()>0){
        Node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    cout<<endl;
}

//level order traversal with new line
 void levelOrderNewLine(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size()>0){
        Node* temp=q.front();
        
        
        if(temp==NULL){
            if(q.size()>0){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    cout<<endl;

 }


int main(){

    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1,};

    Node* root=buildTree(preorder);
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);
    levelOrderNewLine(root);

    return 0;
}