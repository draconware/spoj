#include<bits/stdc++.h>
using namespace std;

#define MAX 109

int arr[109][109];
bool mark[109][109];
int level[109][109];

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
 	freopen("output.out","w",stdout);
  	#endif

  	int t;
  	cin>>t;

  	while(t--){
  		int n,m,x;
  		cin>>n>>m;

  		for(int i=1;i<=n;i++){
  			for(int j=1;j<=m;j++){
  				cin>>arr[i][j];
  			}
  		}
  		for(int i=0;i<MAX;i++){for(int j=0;j<MAX;j++){level[i][j]=INT_MAX;}}
  		int a,b,c,ans;
  		cin>>a>>b>>c;
  		memset(mark,0,sizeof(mark));
  		multiset< pair<int,pair<int,int> > > q;
  		q.insert(make_pair(arr[1][1],make_pair(1,1)));
  		level[1][1] = arr[1][1];
  		while(!q.empty()){
  			pair<int,pair<int,int> > p = *q.begin();q.erase(q.begin());
  			int x = p.second.first,y = p.second.second,w = p.first;
  			if(mark[x][y]){continue;}
  			mark[x][y]=true;
  			//cout<<x<<","<<y<<" "<<level[x][y]<<"------ "<<endl;
  			if(x == a && y == b){ans = w;break;}
  			if(x-1>0 && !mark[x-1][y]){
  				if(level[x-1][y] > w + arr[x-1][y]){
  					q.insert(make_pair(w + arr[x-1][y],make_pair(x-1,y)));
  					level[x-1][y] = w + arr[x-1][y];
  					//cout<<"executed1 "<<x-1<<","<<y<<","<<level[x-1][y]<<endl;
  				}
  			}
  			if(y-1>0 && !mark[x][y-1]){
  				if(level[x][y-1] > w + arr[x][y-1]){
  					q.insert(make_pair(level[x][y] + arr[x][y-1],make_pair(x,y-1)));
  					level[x][y-1] = level[x][y] + arr[x][y-1];
  					//cout<<"executed2 "<<x<<","<<y-1<<","<<level[x][y-1]<<endl;
  				}
  			}if(x+1<=n && !mark[x+1][y]){
  				if(level[x+1][y] > level[x][y] + arr[x+1][y]){
  					q.insert(make_pair(level[x][y] + arr[x+1][y],make_pair(x+1,y)));
  					level[x+1][y] = level[x][y] + arr[x+1][y];
  					//cout<<"executed3 "<<x+1<<","<<y<<","<<level[x+1][y]<<endl;
  				}
  			}if(y+1<=m && !mark[x][y+1]){
  				if(level[x][y+1] > level[x][y] + arr[x][y+1]){
  					q.insert(make_pair(level[x][y] + arr[x][y+1],make_pair(x,y+1)));
  					level[x][y+1] = level[x][y] + arr[x][y+1];
  					//cout<<"executed4 "<<x<<","<<y+1<<","<<level[x][y+1]<<endl;
  				}
  			}
  		}
  		
  		if(mark[a][b]){
  			if(level[a][b] <= c){
  				cout<<"YES"<<endl;
  				cout<<c-level[a][b]<<endl;
  			}else{
  				cout<<"NO"<<endl;
  			}
  		}else{
  			cout<<"NO"<<endl;
  		}
  	}
  	return 0;
}