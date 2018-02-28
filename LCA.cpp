#include<bits/stdc++.h>
using namespace std;

vector<int> v[1009];
vector<int> level(1009,0),p(1009,-1),t(1009,-1);
int val;

void dfs_parent(int x){
	for(int i=0;i<v[x].size();i++){
		level[v[x][i]]=level[x]+1;
		val=max(val,level[v[x][i]]);
		t[v[x][i]]=x;
		dfs_parent(v[x][i]);
	}
}

void dfs(int x){
	mark[x]=true;
	if(level[x] < val){
		p[x]=1;
	}else if(level[x]%val == 0){
		p[x]=t[x];
	}else{
		p[x]=p[t[x]];
	}

	for(int i=0;i<v[x].size();i++){
		if(!mark[v[x][i]]){
			dfs(v[x][i]);
		}
	}
}

int lca(int x,int y){
	while(p[x]!=p[y]){
		if(level[x]<level[y]){
			y=p[y];
		}else{
			x=p[x];
		}
	}
	while(x!=y){
		if(level[x]<level[y]){
			y=t[y];
		}else{
			x=t[x];
		}
	}
	return x;
}

int main(){
	int r;
	cin>>r;

	while(r--){
		for(int i=0;i<1009;i++){
			v[i].clear();level[i]=0;p[i]=-1;t[i]=-1;
		}
		int n,m;
		cin>>n;

		for(int i=1;i<=n;i++){
			cin>>m;
			int x;
			while(m--){
				cin>>x;
				v[i].push_back(x);
			}
		}
		val=0;
		dfs_parent(1);
		memset(mark,0,sizeof(mark));
		val = (int)sqrt(val);
		dfs(1);

		int q;
		cin>>q;
		while(q--){
			int x,y;
			cin>>x>>y;

			cout<<lca(x,y)<<endl;
		}
	}
	return 0;
}