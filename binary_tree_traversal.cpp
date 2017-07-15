#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* new_node(int new_data){
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data=new_data;
    node->left=NULL;
    node->right=NULL;

    return node;
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }else{
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }else{
        postorder(root->left);
        postorder(root->right);

        cout<<root->data<<" ";
    }
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    struct node* root=new_node(1);
    root->left=new_node(2);
    root->right=new_node(3);
    root->left->left=new_node(4);
    root->left->right=new_node(5);

    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    return 0;
}
