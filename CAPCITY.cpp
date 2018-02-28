#include<bits/stdc++.h>
using namespace std;

vector<int> G[100009];
vector<int> RG[100009];
stack<int> s;
bool mark[100009];
int scc[100009];
vector<int> res[100009];

void dfs(int u){
	mark[u]=true;
	for(int i=0;i<(int)G[u].size();i++){
		int v = G[u][i];
		if(!mark[v]){
			dfs(v);
		}
	}
	s.push(u);
}

void dfs1(int u,int k){
	mark[u]=true;
	scc[u] = k;
	for(int i=0;i<(int)RG[u].size();i++){
		int v = RG[u][i];
		if(!mark[v]){dfs1(v,k);}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;

		G[a].push_back(b);
		RG[b].push_back(a);
	}

	for(int i=1;i<=n;i++){
		if(!mark[i]){dfs(i);}
	}

	for(int i=1;i<=n;i++){scc[i] = i;}

	int k=0;
	memset(mark,0,sizeof(mark));
	while(!s.empty()){
		if(!mark[s.top()]){
			k++;
			dfs1(s.top(),k);
		}
		s.pop();
	}

	for(int i=1;i<=n;i++){
		res[scc[i]].push_back(i);
	}
	cout<<k<<endl;
	vector<int> ans;
	for(int i=1;i<=k;i++){
		ans.push_back(res[i][0]);
	}

	sort(ans.begin(),ans.end());
	for(int i=0;i<(int)ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}