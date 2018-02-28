#include<bits/stdc++.h>
using namespace std;

struct node{
	int id;
	struct node* left;
	struct node* right;
};

string s;
int arr[10009],c=0,c1=1;
vector<int> G[10009];
int dp[10009][2][2][2];
int inf = 1000000;

struct node* new_node(){
	struct node* root = (struct node*)malloc(sizeof(struct node));
	root->left = NULL;
	root->right = NULL;
	return root;
}

struct node* build(struct node* root){
	if(c>=(int)s.length()){return NULL;}
	root = new_node();
	root->id = c1++;
	if(arr[c]==0){
		c++;		
	}else if(arr[c]==1){
		c++;
		root->left = build(root->left);
	}else{
		c++;
		root->left = build(root->left);
		root->right = build(root->right);
	}
	return root;
}

void reform_data_to_graph(struct node* root){
	if(root == NULL){return ;}
	int x = root->id;
	if(root->left != NULL){
		G[x].push_back(root->left->id);
	}
	if(root->right != NULL){
		G[x].push_back(root->right->id);
	}
	reform_data_to_graph(root->left);
	reform_data_to_graph(root->right);
	return ;
}

int f(int id,int x,int y,int z){
	if(dp[id][x][y][z]!=-1){return dp[id][x][y][z];}

	int sum = 0;
	int size = (int)G[id].size();
	if(size == 1){
		if(x==1){
			sum = max(sum,f(G[id][0],0,1,0));
			sum = max(sum,1+f(G[id][0],0,0,1));
		}else if(y==1){
			sum = max(sum,f(G[id][0],1,0,0));
			sum = max(sum,1+f(G[id][0],0,0,1));
		}else{
			sum = max(sum,f(G[id][0],1,0,0));
			sum = max(sum,f(G[id][0],0,1,0));
		}
	}else if(size == 2){
		if(x==1){
			sum = max(sum,f(G[id][0],0,1,0)+1+f(G[id][1],0,0,1));
			sum = max(sum,1+f(G[id][0],0,0,1)+f(G[id][1],0,1,0));
		}else if(y==1){
			sum = max(sum,f(G[id][0],1,0,0)+1+f(G[id][1],0,0,1));
			sum = max(sum,1+f(G[id][0],0,0,1)+f(G[id][1],1,0,0));
		}else{
			sum = max(sum,f(G[id][0],0,1,0)+f(G[id][1],1,0,0));
			sum = max(sum,f(G[id][0],1,0,0)+f(G[id][1],0,1,0));
		}
	}
	dp[id][x][y][z] = sum;
	return sum;
}

int f1(int id,int x,int y,int z){
	if(dp[id][x][y][z]!=-1){return dp[id][x][y][z];}

	int sum = inf;
	int size = (int)G[id].size();
	if(size == 1){
		if(x==1){
			sum = min(sum,f1(G[id][0],0,1,0));
			sum = min(sum,1+f1(G[id][0],0,0,1));
		}else if(y==1){
			sum = min(sum,f1(G[id][0],1,0,0));
			sum = min(sum,1+f1(G[id][0],0,0,1));
		}else{
			sum = min(sum,f1(G[id][0],1,0,0));
			sum = min(sum,f1(G[id][0],0,1,0));
		}
	}else if(size == 2){
		if(x==1){
			sum = min(sum,f1(G[id][0],0,1,0)+1+f1(G[id][1],0,0,1));
			sum = min(sum,1+f1(G[id][0],0,0,1)+f1(G[id][1],0,1,0));
		}else if(y==1){
			sum = min(sum,f1(G[id][0],1,0,0)+1+f1(G[id][1],0,0,1));
			sum = min(sum,1+f1(G[id][0],0,0,1)+f1(G[id][1],1,0,0));
		}else{
			sum = min(sum,f1(G[id][0],0,1,0)+f1(G[id][1],1,0,0));
			sum = min(sum,f1(G[id][0],1,0,0)+f1(G[id][1],0,1,0));
		}
	}else{
		sum = 0;
	}
	dp[id][x][y][z] = sum;
	return sum;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		for(int i=0;i<10009;i++){
			G[i].clear();
		}
		cin>>s;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<(int)s.length();i++){
			arr[i] = s[i]-'0';
		}
		c=0;c1=1;
		struct node* root = build(root);

		reform_data_to_graph(root);
		memset(dp,-1,sizeof(dp));
		int ans_max = max(f(1,1,0,0),max(f(1,0,1,0),1+f(1,0,0,1)));

		memset(dp,-1,sizeof(dp));
		int ans_min = min(f1(1,1,0,0),max(f1(1,0,1,0),1+f1(1,0,0,1)));
		cout<<ans_max<<" "<<ans_min<<endl;
	}
	return 0;
}