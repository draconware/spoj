#include<bits/stdc++.h>
using namespace std;

int n,m;
bool chk(int i,int j){
	if(i>=0 && i<n && j>=0 && j<m){return true;}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int sx,sy;
	cin>>m>>n;

	char arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='C'){sx=i;sy=j;}
		}
	}

	int level[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			level[i][j]=INT_MAX;
		}
	}

	queue<pair<int,pair<int,int> > > q;
	q.push(make_pair(0,make_pair(sx,sy)));

	level[sx][sy]=0;
	while(!q.empty()){
		pair<int,pair<int,int> > p = q.front();q.pop();
		int x = p.second.first,y = p.second.second,d = p.first;

		if(chk(x-1,y)){
			if(arr[x-1][y]=='.' || arr[x-1][y]=='C'){
				if(d==0 || d==1){
					if(level[x-1][y] > level[x][y]){
						level[x-1][y]=level[x][y];
						q.push(make_pair(1,make_pair(x-1,y)));
					}
				}else if(d==2 || d==4){
					if(level[x-1][y] > level[x][y]+1){
						level[x-1][y]=level[x][y]+1;
						q.push(make_pair(1,make_pair(x-1,y)));
					}
				}
			}
		}
		if(chk(x+1,y)){
			if(arr[x+1][y]=='.' || arr[x+1][y]=='C'){
				if(d==0 || d==3){
					if(level[x+1][y] > level[x][y]){
						level[x+1][y]=level[x][y];
						q.push(make_pair(3,make_pair(x+1,y)));
					}
				}else if(d==2 || d==4){
					if(level[x+1][y] > level[x][y]+1){
						level[x+1][y]=level[x][y]+1;
						q.push(make_pair(3,make_pair(x+1,y)));
					}
				}
			}
		}
		if(chk(x,y-1)){
			if(arr[x][y-1]=='.' || arr[x][y-1]=='C'){
				if(d==0 || d==4){
					if(level[x][y-1] > level[x][y]){
						level[x][y-1]=level[x][y];
						q.push(make_pair(4,make_pair(x,y-1)));
					}
				}else if(d==1 || d==3){
					if(level[x][y-1] > level[x][y]+1){
						level[x][y-1]=level[x][y]+1;
						q.push(make_pair(4,make_pair(x,y-1)));
					}
				}
			}
		}
		if(chk(x,y+1)){
			if(arr[x][y+1]=='.' || arr[x][y+1]=='C'){
				if(d==0 || d==2){
					if(level[x][y+1] > level[x][y]){
						level[x][y+1]=level[x][y];
						q.push(make_pair(2,make_pair(x,y+1)));
					}
				}else if(d==1 || d==3){
					if(level[x][y+1] > level[x][y]+1){
						level[x][y+1]=level[x][y]+1;
						q.push(make_pair(2,make_pair(x,y+1)));
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='C'){ans = max(ans,level[i][j]);}
		}
	}
	cout<<ans<<endl;
}