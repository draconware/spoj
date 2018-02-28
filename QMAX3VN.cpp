#include<bits/stdc++.h>
using namespace std;

struct node{
	int size,h,max_h,prio;
	struct node *left,*right;
};

void update(struct node* root){
	if(root == NULL){return ;}
	root->size = 1;
	root->max_h = root->h;
	if(root->left != NULL){
		root->size += root->left->size;
		root->max_h = max(root->max_h,root->left->max_h);
	}
	if(root->right != NULL){
		root->size += root->right->size;
		root->max_h = max(root->max_h,root->right->max_h);
	}
}

struct node* new_node(int val){
	struct node* root = new node;
	root->size = 1;
	root->left = root->right = NULL;
	root->max_h = root->h = val;
	root->prio = rand();
	return root;
}

struct node* rotate(struct node* x,struct node* y){
	if(x->left == y){
		x->left = y->right;
		y->right = x;
	}else{
		x->right = y->left;
		y->left = x;
	}
	update(x);update(y);
}

struct node* insert(struct node* tree,int pos,int val){
	if(tree == NULL){
		return new_node(val);
	}
	if(tree->left->size >= pos){
		tree->left = insert(tree->left,pos,val);
		if(tree->prio < tree->left->prio){
			tree = rotate(tree,tree->left);
		}
	}
}

int main(){
	srand(time(NULL));
	struct node *tree = NULL;

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		char c;cin>>c;
		int x,y;cin>>x>>y;

		if(c=='A'){
			tree = insert(tree,y,x);
		}else{
			cout<<query(tree,1,tree->size,x,y)<<endl;
		}
	}
}