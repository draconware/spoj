#include<bits/stdc++.h>
using namespace std;

char arr[21][21];
int n,m,k;
int level[21][21];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
bool mark[21][21];

int bfs(pair<int,int> &s){
	queue<pair<int,pair<int,int> > > q;
	q.push(make_pair(k,s));
	level[s.first][s.second] = 0;
	if(k==0){return 0;}

	while(!q.empty()){
		pair<int,int> u = q.front().second;
		int umask = q.front().first;
		q.pop();

		for(int i=0;i<4;i++){
			pair<int,int> v = make_pair(u.first+x[i],u.second+y[i]);
			if(arr[v.first][v.second]=='*'){umask--;}
			if(umask==0){return level[u.first][u.second]+1;}

			arr[v.first][v.second]='.';
			q.push(make_pair(umask,v));
		}
	}
}

int main(){
	while(1){
		cin>>m>>n;
		if(n==0 && m==0){return 0;}

		k=0;
		pair<int,int> start;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
				if(arr[i][j]=='o'){start = make_pair(i,j);}
				if(arr[i][j]=='*'){k++;}
			}
		}
		memset(mark,0,sizeof(mark));
		cout<<bfs(start)<<endl;
	}
}