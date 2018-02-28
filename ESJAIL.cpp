#include<bits/stdc++.h>
using namespace std;

vector<int> G[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(1){
		int n,k,m;
		cin>>n>>k>>m;
		if(n==-1){return 0;}
		for(int i=1;i<=n;i++){G[i].clear();}
		int ch[n+1],rch[n+1];
		memset(ch,0,sizeof(ch));
		memset(rch,0,sizeof(rch));
		//memset(door,0,sizeof(door));
		for(int i=0;i<k;i++){
			int a,b;cin>>a>>b;
			ch[b]=a;
			rch[a]=b;
		}
		for(int i=0;i<m;i++){
			int a,b;cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		int vis[n+1];
		memset(vis,0,sizeof(vis));
		bool flag = false;
		queue<int> q;
		if(ch[1]==0){q.push(1);vis[1]=2;}

		while(!q.empty()){
			int u = q.front();q.pop();
			//cout<<u<<" ";
			if(u==n){flag=true;break;}

			for(int i=0;i<G[u].size();i++){
				int v = G[u][i];
				if(vis[v]==0){
					if(ch[v]==0 || vis[ch[v]]==2){
						q.push(v);vis[v]=2;
						while(vis[rch[v]]==1){
							q.push(rch[v]);vis[rch[v]]=2;
							v = rch[v];
						}
					}else{
						vis[v]=1;
					}
				}
			}
		}
		//cout<<endl;
		if(flag){cout<<"Y"<<endl;}
		else{cout<<"N"<<endl;}
	}
}