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

int main(){
    struct node* root=new_node(1);
    root->left=new_node(2);
    root->right=new_node(3);

    root->left->left=new_node(4);
    root->right->right=new_node(5);

    return 0;
}
