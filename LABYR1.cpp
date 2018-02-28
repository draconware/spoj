#include<bits/stdc++.h>
using namespace std;

int c,r;
bool chk(int i,int j){
	if(i>=0 && i<c && j>=0 && j<r){return true;}
	return false;
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
		cin>>r>>c;

		char arr[c][r];
		for(int i=0;i<c;i++){
			for(int j=0;j<r;j++){
				cin>>arr[i][j];
			}
		}
		bool mark[c][r];
		memset(mark,0,sizeof(mark));

		queue<pair<int,int> > q;
		int level[c][r];

		for(int i=0;i<c;i++){
			for(int j=0;j<r;j++){
				if(!mark[i][j] && arr[i][j]=='.'){
					queue<pair<int,int> > q;
					q.push(make_pair(i,j));

					level[i][j]=0;
					while(!q.empty()){
						pair<int,int> p = q.front();q.pop();
						int x=p.first,y=p.second;
						mark[x][y]=true;

						if(chk(x-1,y)){
							if(!mark[x-1][y] && arr[x-1][y]=='.'){
								level[x-1][y]=level[x][y]+1;
								q.push(make_pair(x-1,y));
							}
						}
						if(chk(x+1,y)){
							if(!mark[x+1][y] && arr[x+1][y]=='.'){
								level[x+1][y]=level[x][y]+1;
								q.push(make_pair(x+1,y));
							}
						}
						if(chk(x,y-1)){
							if(!mark[x][y-1] && arr[x][y-1]=='.'){
								level[x][y-1]=level[x][y]+1;
								q.push(make_pair(x,y-1));
							}
						}
						if(chk(x,y+1)){
							if(!mark[x][y+1] && arr[x][y+1]=='.'){
								level[x][y+1]=level[x][y]+1;
								q.push(make_pair(x,y+1));
							}
						}
					}
				}
			}
		}
		int s=-1,e=-1,l=-1;
		for(int i=0;i<c;i++){
			for(int j=0;j<r;j++){
				if(arr[i][j]=='.'){
					if(l<level[i][j]){l=level[i][j];s=i;e=j;}
				}
			}
		}
		cout<<"Maximum rope length is ";
		if(s==-1 || e==-1 || l==0){cout<<"0."<<endl;}
		else{
			memset(mark,0,sizeof(mark));
			queue<pair<int,int> > q;
			q.push(make_pair(s,e));

			level[s][e]=0;
			while(!q.empty()){
				pair<int,int> p = q.front();q.pop();
				int x=p.first,y=p.second;
				mark[x][y]=true;

				if(chk(x-1,y)){
					if(!mark[x-1][y] && arr[x-1][y]=='.'){
						level[x-1][y]=level[x][y]+1;
						q.push(make_pair(x-1,y));
					}
				}
				if(chk(x+1,y)){
					if(!mark[x+1][y] && arr[x+1][y]=='.'){
						level[x+1][y]=level[x][y]+1;
						q.push(make_pair(x+1,y));	
					}
				}
				if(chk(x,y-1)){
					if(!mark[x][y-1] && arr[x][y-1]=='.'){
						level[x][y-1]=level[x][y]+1;
						q.push(make_pair(x,y-1));
					}
				}
				if(chk(x,y+1)){
					if(!mark[x][y+1] && arr[x][y+1]=='.'){
						level[x][y+1]=level[x][y]+1;
						q.push(make_pair(x,y+1));
					}
				}
			}
			l=0;
			for(int i=0;i<c;i++){
				for(int j=0;j<r;j++){
					if(arr[i][j]=='.'){l=max(l,level[i][j]);}
				}
			}
			cout<<l<<"."<<endl;
		}
	}
}