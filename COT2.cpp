#include<bits/stdc++.h>
using namespace std;

int weight[40009];
int parent[40009];
int long_parent[40009];
int height[40009];
int sqrt_size;
int st[40009],fin[40009];
int t=0;
int arr[80009];
int additional_query[100009];
vector<pair<int,pair<int,int> > > queries;
int value[80009];
int ans;
vector<int> G[80009];
int mos_sqrt;
int times[80009];

void dfs(int u,int p){
	parent[u] = p;
	height[u] = height[p] + 1;

	for(int i=0;i<(int)G[u].size();i++){
		int v = G[u][i];
		if(v!=p){
			dfs(v,u);
		}
	}
}

void dfs2(int u,int p){
	if(height[u]%sqrt_size == 0){
		long_parent[u] = parent[u];
	}else{
		long_parent[u] = long_parent[p];
	}
	for(int i=0;i<(int)G[u].size();i++){
		int v = G[u][i];
		if(v!=p){dfs2(v,u);}
	}
}

void dfs_order(int u,int p){
	st[u]=t;
	arr[t++] = u;
	for(int i=0;i<(int)G[u].size();i++){
		int v = G[u][i];
		if(v!=p){
			dfs_order(v,u);
		}
	}
	fin[u]=t;
	arr[t++] = u;
}

int lca(int x,int y){
	while(x!=y){
		if(x>y){
			int temp = x;
			x = y;y = temp;
		}
		if(long_parent[x] == long_parent[y]){
			y = parent[y];
		}else{
			y = long_parent[y];
		}
	}
	return x;
}

bool compa(pair<int,pair<int,int> > x,pair<int,pair<int,int> > y){
	int a = x.second.first/mos_sqrt;
	int b = y.second.first/mos_sqrt;
	if(a!=b){
		return a<b;
	}else{
		return (x.second.second < y.second.second);
	}
}

void remove(int x,int y){
	times[y]^=1;
	if(times[y] == 0){
		value[x]--;
		if(value[x]==0){ans--;}
	}
}

void add(int x){
	times[y]^=1;
	if(times[y] == 0){
		value[x]++;
		if(value[])
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

	for(int i=1;i<=n;i++){cin>>weight[i];}

	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;

		G[a].push_back(b);
		G[b].push_back(a);
	}


	height[0] = -1;
	dfs(1,0);
	int max_height = 0;
	for(int i=1;i<=n;i++){
		max_height = max(max_height,height[i]);
	}

	sqrt_size = (int)sqrt((float)max_height);
	dfs2(1,0);

	dfs_order(1,0);
//	cout<<"executed"<<endl;
	
	//cout<<endl;
	mos_sqrt = (int)(sqrt((float)t));


	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;

		if(height[a] > height[b]){
			int temp=a;
			a = b;
			b = temp;
		}
		int u = lca(a,b);
		//cout<<a<<","<<b<<"---- "<<u<<endl;
		if(u == a){
			queries.push_back(make_pair(i,make_pair(min(st[a],st[b]),max(st[a],st[b]))));
			additional_query[i] = -1;
		}else{
			queries.push_back(make_pair(i,make_pair(min(fin[a],st[b]),max(fin[a],st[b]))));
			additional_query[i] = st[u];
		}
	}

	sort(queries.begin(),queries.end(),compa);

	int mos_left=0,mos_right=-1;
	ans = 0;
	int final_res[m];

	for(int i=0;i<(int)queries.size();i++){
		int idx = queries[i].first;
		int left = queries[i].second.first;
		int right = queries[i].second.second;
		cout<<mos_left<<","<<left<<" "<<mos_right<<","<<right<<endl;

		cout<<"1 ===== ";
		while(mos_left < left){
			remove(weight[arr[mos_left],mos_left]);
			cout<<weight[arr[mos_left]]<<" ";
			mos_left++;
		}
		cout<<endl;
		cout<<"2 ---- ";
		while(mos_left > left){
			mos_left++;
			cout<<weight[arr[mos_left]]<<" ";
			add(weight[arr[mos_left],mos_left]);
		}
		cout<<endl;
		cout<<"3 ----- ";
		while(mos_right < right){
			mos_right++;
			cout<<weight[arr[mos_right]]<<" ";
			add(weight[arr[mos_right]],mos_right);
		}
		cout<<endl;
		cout<<"4 ---- ";
		while(mos_right > right){
			cout<<weight[arr[mos_right]]<<" ";
			remove(weight[arr[mos_right]],mos_right);
			mos_right--;
		}
		cout<<endl;
		int res = ans;
		if(additional_query[idx] != -1){
			if(value[weight[arr[additional_query[idx]]]]%2 == 0){res++;}
			else{res--;}
		}
		final_res[idx] = res;
	}
	for(int i=0;i<m;i++){
		cout<<final_res[i]<<endl;
	}
	return 0;
}