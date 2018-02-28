#include<bits/stdc++.h>
using namespace std;

char arr[101][101];
int level[101][101][16];
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};
int n,m;

bool chk(int x,int y){
	if(x>=n || x<0 || y>=m || y<0){return false;}
	return true;
}

int bfs(pair<int,int> &s){
	queue<pair<pair<int,int>,int> > q;
	q.push(make_pair(s,0));
	level[s.first][s.second][0]=0;

	while(!q.empty()){
		pair<int,int> u = q.front().first;
		int ubit = q.front().second,vbit;
		q.pop();

		for(int i=0;i<=4;i++){
			pair<int,int> v = make_pair(u.first+x[i],u.second+y[i]);
			if(chk(v.first,v.second) && arr[v.first][v.second]!='#'){
				if(arr[v.first][v.second]=='X'){return level[u.first][u.second][ubit]+1;}
				if(level[v.first][v.second][ubit]==-1){
					vbit = ubit;
					if(islower(arr[v.first][v.second])){
						if(arr[v.first][v.second]=='b'){vbit |= (0x1);}
						if(arr[v.first][v.second]=='y'){vbit |= (0x2);}
						if(arr[v.first][v.second]=='g'){vbit |= (0x4);}
						if(arr[v.first][v.second]=='r'){vbit |= (0x8);}

						q.push(make_pair(v,vbit));
						level[v.first][v.second][ubit] = level[u.first][u.second][ubit]+1;
						level[v.first][v.second][vbit] = level[v.first][v.second][ubit];
					}else if(isupper(arr[v.first][v.second])){
						if(arr[v.first][v.second]=='B'){if(ubit & 0x1){q.push(make_pair(v,vbit));}}
						if(arr[v.first][v.second]=='Y'){if(ubit & 0x2){q.push(make_pair(v,vbit));}}
						if(arr[v.first][v.second]=='G'){if(ubit & 0x4){q.push(make_pair(v,vbit));}}
						if(arr[v.first][v.second]=='R'){if(ubit & 0x8){q.push(make_pair(v,vbit));}}

						level[v.first][v.second][ubit] = level[u.first][u.second][ubit]+1;
						//level[v.first][v.second][vbit] = level[v.first][v.second][ubit];
					}else{
						q.push(make_pair(v,vbit));
						level[v.first][v.second][ubit] = level[u.first][u.second][ubit]+1;
					}
				}
			}
		}
	}
	return -1;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(1){
		//int n,m;
		cin>>n>>m;
		if(n==0 && m==0){return 0;}

		pair<int,int> start;
		for(int i=0;i<n;i++){
			scanf("%s", arr[i]);
			for(int j=0;j<m;j++){
				if(arr[i][j]=='*'){start = make_pair(i,j);}
				for(int k=0;k<16;k++){level[i][j][k] = -1;}
			}
		}

		int d = bfs(start);
		if(d<0){cout<<"The poor student is trapped!"<<endl;}
		else{cout<<"Escape possible in "<<d<<" steps."<<endl;}
	}
}