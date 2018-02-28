#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif
	while(1){
		int n,m;
		cin>>n>>m;
		if(n==0 && m==0){return 0;}

		int arr[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		int res[n*m+9],ans=0;
		memset(res,0,sizeof(res));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==1){
					//cout<<"evaluatong--- "<<i<<" "<<j<<endl;
					ans++;
					queue<pair<int,int> > q;
					q.push(make_pair(i,j));
					int c=0;
					arr[i][j]=0;
					while(!q.empty()){
						c++;
						pair<int,int> p = q.front();q.pop();
						int x = p.first,y = p.second;
						//cout<<"for--- "<<x<<","<<y<<"---- ";
						if(x-1>=0 && arr[x-1][y]==1){
							//cout<<x-1<<","<<y<<" ";
							arr[x-1][y]=0;
							q.push(make_pair(x-1,y));
						}
						if(x+1<n && arr[x+1][y]==1){
							//cout<<x+1<<","<<y<<" ";
							arr[x+1][y]=0;
							q.push(make_pair(x+1,y));
						}
						if(y-1>=0 && arr[x][y-1]==1){
							//cout<<x<<","<<y-1<<" ";
							arr[x][y-1]=0;
							q.push(make_pair(x,y-1));
						}
						if(y+1<m && arr[x][y+1]==1){
							//cout<<x<<","<<y+1<<" ";
							arr[x][y+1]=0;
							q.push(make_pair(x,y+1));
						}
						//cout<<endl;
					}
					//cout<<c<<endl;
					res[c]++;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=(n*m);i++){
			if(res[i]>0){
				cout<<i<<" "<<res[i]<<endl;
			}
		}
	}
	return 0;
}