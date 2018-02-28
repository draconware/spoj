#include<bits/stdc++.h>
using namespace std;

int n,m;

bool chk(int x,int y){if(x<0 || x>=n || y<0 || y>=m){return false;}return true;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;
	int x[4]={0,0,-1,1};
	int y[4]={1,-1,0,0};

	while(t--){
		//int n,m;
		cin>>n>>m;

		char arr[n][m];
		pair<int,int> start = {-1,-1};
		for(int i=0;i<n;i++){
			cin>>arr[i];
			for(int j=0;j<m;j++){
				if(arr[i][j]=='X'){start = make_pair(i,j);}
			}
		}
		if(start.first==-1 && start.second==-1){cout<<"-1"<<endl;continue;}
		int level[n][m];
		bool mark[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				level[i][j] = INT_MAX;
			}
		}
		memset(mark,0,sizeof(mark));
		multiset<pair<int,pair<int,int> > > q;
		q.insert(make_pair(0,start));
		level[start.first][start.second] = 0;

		while(!q.empty()){
			pair<int,int> u = (*q.begin()).second;q.erase(q.begin());
			//if(mark[u.first][u.second]){continue;}
			mark[u.first][u.second] = true;

			for(int i=0;i<4;i++){
				pair<int,int> v = make_pair(u.first+x[i],u.second+y[i]);
				if(chk(v.first,v.second) && !mark[v.first][v.second]){
					int sum;
					if(arr[u.first][u.second]=='X' || arr[u.first][u.second]=='$' || arr[v.first][v.second]=='X' || arr[v.first][v.second]=='$'){sum=2;}
					else{if(abs(arr[u.first][u.second] - arr[v.first][v.second])==0){sum=1;}else{sum=3;}}
					if(level[v.first][v.second] > level[u.first][u.second]+sum){
						level[v.first][v.second] = level[u.first][u.second]+sum;
						q.insert(make_pair(level[v.first][v.second],v));
					}
				}
			}
		}

		vector<int> v;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]=='$'){v.push_back(level[i][j]);}
			}
		}
		sort(v.beign(),v.end());
		for(int i=0;i<v.size()-2;i++){v[i]*=2;}

		
	}
}