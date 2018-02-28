#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	char data;
	struct node* left;
	struct node* right;
};
string s;
int i=0,ans=0;

struct node* get_node(){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = s[i];

	if(s[i]=='n'){
		i++;
		temp->left = get_node();
		temp->right = get_node();
	}else{
		i++;
		temp->left = temp->right = NULL;
	}
	return temp;
}

void depth(struct node* root){
	if(root == NULL){return ;}
	ans = max(ans,root->d);
	if(root->left != NULL){root->left->d = root->d +1;}
	if(root->right != NULL){root->right->d = root->d +1;}

	depth(root->left);
	depth(root->right);
}

void print(struct node* root){
	if(root==NULL){return ;}
	cout<<root->data;
	if(root->data == 'n'){
		print(root->left);
		print(root->right);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		s.clear();
		cin>>s;
		i=0;ans=0;
		struct node* root = get_node();
		//cout<<"executed"<<endl;
		//print(root);
		root->d = 0;
		//cout<<"executed"<<endl;
		depth(root);
		//cout<<"executed"<<endl;
		cout<<ans<<endl;
	}
	return 0;
}