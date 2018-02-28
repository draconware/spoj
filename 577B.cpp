#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
bool vis[1009][1009][2];
bool val[1009][1009][2];

bool dp(int i,int x,int p){
	if(i==n){
		if(p==1 && x==0){return true;}
		else{return false;}
	}
	if(vis[i][x][p]){return val[i][x][p];}
	vis[i][x][p]=true;
	if(p==0){
		if(dp(i+1,sum,0)){
			val[i][sum][p]=true;
		}else if(dp(i+1,(sum+v[i])%m,1)){
			val[i][sum][0]=true;
		}else{
			val[i][sum][0]=false;
		}
	}else{
		if(dp(i+1,sum,p)){
			val[i][sum][p]=true;
		}else if(dp(i+1,(sum+v[i])%m,p)){
			val[i][sum][p]=true;
		}else{
			val[i][sum][p]=false;
		}
	}
	return val[i][sum][p];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	cin>>n>>m;

	for(int i=0,x;i<n;i++){cin>>x;v.push_back(x%m);}

	if(n>m){
		cout<<"YES"<<endl;
	}else{
		memset(vis,0,sizeof(vis));
		memset(val,0,sizeof(val));
		if(dp(0,0,0)){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
}