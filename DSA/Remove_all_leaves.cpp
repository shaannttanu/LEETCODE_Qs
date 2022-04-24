#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> ans;

class BinaryTree{
    
    public:
        int data;
        BinaryTree *left;
        BinaryTree *right;


        BinaryTree(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
};

BinaryTree *removeAllLeaves(BinaryTree *root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    root->left=removeAllLeaves(root->left);
    root->right=removeAllLeaves(root->right);

    return root;
}

void inOrder(BinaryTree *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
int main()
{
    BinaryTree *root=new BinaryTree(10);
    BinaryTree *node1=new BinaryTree(6);
    BinaryTree *node2=new BinaryTree(11);
    BinaryTree *node3=new BinaryTree(4);
    BinaryTree *node4=new BinaryTree(7);
    BinaryTree *node5=new BinaryTree(14);

    root->left=node1;
    root->right=node2;

    node1->left=node3;
    node1->right=node4;

    node2->right=node5;

    inOrder(root);

    cout<<endl;
    BinaryTree *newRoot=removeAllLeaves(root);
    inOrder(newRoot);
    return 0;
}