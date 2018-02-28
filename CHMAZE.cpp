#include<bits/stdc++.h>
using namespace std;

int level[11][21][21];
bool mark[11][21][21];
int n,m,k;
int x[5]={0,0,0,-1,1};
int y[5]={0,1,-1,0,0};
char arr[11][21][21];

bool chk(int i,int j){
	if(i<0 || i>=n || j<0 || j>=m){return false;}return true;
}

int bfs(){
	queue<pair<int,pair<int,int> > > q;
	q.push(make_pair(0,make_pair(0,0)));
	mark[0][0][0]=true;
	level[0][0][0]=0;
	if(n==0 && m==0){return 0;}

	while(!q.empty()){
		int no = q.front().first;
		pair<int,int> u = q.front().second;
		q.pop();
		
		for(int i=0;i<5;i++){
			pair<int,int> v = make_pair(u.first+x[i],u.second+y[i]);
			if(chk(v.first,v.second) && arr[(no+1)%k][v.first][v.second]=='0'){
				if(!mark[(no+1)%k][v.first][v.second]){
					mark[(no+1)%k][v.first][v.second] = true;
					level[(no+1)%k][v.first][v.second] = level[no][u.first][u.second]+1;
					q.push(make_pair((no+1)%k,v));
					if(v.first==n-1 && v.second==m-1){return level[no][u.first][u.second]+1;}
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

	//int n,m,k;
	int l=0;
	while(1){
		//cout<<"executed"<<endl;
		l++;
		cin>>n>>m>>k;
		if(n==0 && m==0 && k==0){return 0;}

		//char arr[k][n][m];
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		memset(level,-1,sizeof(level));
		memset(mark,0,sizeof(mark));
		int d = bfs();
		cout<<"Case "<<l<<": ";
		if(d<0){cout<<"Luke and Leia cannot escape."<<endl;}
		else{cout<<"Luke and Leia can escape in "<<d<<" steps."<<endl;}
	}
}