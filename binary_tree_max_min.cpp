#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* new_node(int new_data){
    struct node* node= (struct node*)malloc(sizeof(struct node));

    node->data=new_data;
    node->left=NULL;
    node->right=NULL;

    return node;
}

int maximum(struct node* root){
    if(root==NULL){
        return INT_MAX;
    }else{
        int res=root->data;
        int lres=maximum(root->left);
        int rres=maximum(root->right);

        if(rres<res){
            res=rres;
        }
        if(lres<res){
            res=lres;
        }
        return res;
    }
}

int main(){
    struct node* root=new_node(2);
    root->left=new_node(7);
    root->left->right=new_node(6);
    root->left->right->left=new_node(1);
    root->left->right->right=new_node(11);

    root->right=new_node(5);
    root->right->right=new_node(9);
    root->right->right->left=new_node(4);

    cout<<maximum(root)<<endl;
}
