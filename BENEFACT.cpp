#include<bits/stdc++.h>
using namespace std;

#define MAX 50009

vector<pair<int,int> > v[MAX];
bool mark[MAX];

int main(){

	//#ifndef ONLINE_JUDGE
  	//freopen("input.in","r",stdin);
 	//freopen("output.out","w",stdout);
  	//#endif

	int t;
	cin>>t;

	while(t--){
		for(int i=0;i<MAX;i++){v[i].clear();mark[i]=false;}
		int n,x,y,z;
		cin>>n;

		for(int i=0;i<n-1;i++){
			cin>>x>>y>>z;
			v[x].push_back(make_pair(y,z));
			v[y].push_back(make_pair(x,z));
		}
		queue< pair<int,pair<int,int> > > q;
		q.push(make_pair(0,make_pair(1,0)));
		pair<int,int> p;
		p.first=1;p.second=0;

		while(!q.empty()){
			pair<int,pair<int,int> > l = q.front();q.pop();
			int x = l.second.first,w = l.second.second;
			if(p.second < l.first){p = make_pair(l.second.first,l.first);}
			mark[x]=true;

			for(int i=0;i<v[x].size();i++){
				if(!mark[ v[x][i].first ]){
					q.push(make_pair(w + v[x][i].second , v[x][i] ));
				}
			}
		}
		//cout<<p.first<<endl;
		memset(mark,0,sizeof(mark));

		//queue< pair<int,pair<int,int> > > q;
		q.push(make_pair(0,make_pair(p.first,0)));
		//pair<int,int> p;
		//p.first=1;p.second=0;
		int ans=0;
		while(!q.empty()){
			pair<int,pair<int,int> > l = q.front();q.pop();
			int x = l.second.first,w = l.first;
			//if(p.second < l.first){p = make_pair(l.second.first,l.first);}
			ans = max(ans,l.first);
			mark[x]=true;
			//cout<<x<<" "<<l.first<<endl;
			for(int i=0;i<v[x].size();i++){
				if(!mark[ v[x][i].first ]){
					q.push(make_pair(w + v[x][i].second , v[x][i] ));
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}