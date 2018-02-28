#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int> > > v[109];
bool mark[109][20009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		for(int i=0;i<109;i++){v[i].clear();}
		memset(mark,0,sizeof(mark));
		int k,n,r,c,y,a,b,x;
		cin>>k>>n>>r;

		for(int i=0;i<r;i++){
			cin>>c>>y>>a>>b;
			v[c].push_back(make_pair(y,make_pair(a,b)));
		}

		priority_queue<pair<int,pair<int,int> > > q;
		q.push(make_pair(1,make_pair(0,0)));

		int ans=-1;
		while(!q.empty()){
			pair<int,pair<int,int> > p = q.top();q.pop();
			x = p.first;
			int len = p.second.first,wei = p.second.second;
			if(mark[x][wei]){continue;}
			mark[x][wei]=true;
			
			if(x == n){ans = len;break;}
			for(int i=v[x].size()-1;i>=0;i--){
				y = v[x][i].first;
				int l = len + v[x][i].second.first;
				c = wei + v[x][i].second.second;

				if(c<= k){q.push(make_pair(y,make_pair(l,c)));}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}