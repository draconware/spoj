#include<bits/stdc++.h>
using namespace std;

int n,i=0;
int pre[8009],post[8009],in[8009];
bool flag=true;
struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* new_node(){
	struct node* x;
	x = (struct node*)malloc(sizeof(struct node));
	x->left = x->right = NULL;
	return x;
}

struct node* f(int l,int r){
	if(l>r || i==n){return NULL;}

	int j=l;
	for(;j<=r;j++){
		if(in[j]==pre[i]){break;}
	}
	if(j==r+1){return NULL;}
	else{
		struct node* root = new_node();
		root->data = pre[i];i++;
		root->left = f(l,j-1);
		root->right = f(j+1,r);
		return root;
	}
}

void postorder(struct node* root){
	if(root == NULL){return ;}
	postorder(root->left);
	postorder(root->right);
	//cout<<root->data<<","<<post[i]<<" ";
	if(root->data != post[i]){flag=false;}
	i++;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	cin>>n;
	for(int j=0;j<n;j++){cin>>pre[j];}
	for(int j=0;j<n;j++){cin>>post[j];}
	for(int j=0;j<n;j++){cin>>in[j];}

	struct node* root;
	root = (struct node*)malloc(sizeof(struct node));
	root = f(0,n-1);

	i=0;
	postorder(root);//cout<<endl;
	if(flag){cout<<"yes"<<endl;}
	else{cout<<"no"<<endl;}
}