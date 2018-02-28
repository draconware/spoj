#include<bits/stdc++.h>
using namespace std;

int n,m,b,mod;
int val[509][509][509];
int cost[509];

int dp(int x,int y,int z){
	if(z<0){return 0;}
	if(y<0){return 0;}
	if(z>=0 && y==0){return (1)%m;}
	if(x==n){return 0;}

	if(val[x][y][z] != -1){return (val[x][y][z])%m;}
	int sum=0,y1=y;
	while(y>0){
		sum = (sum+dp(x+1,y-1,z-cost[x]))%m;
		y--;
	}
	val[x][y1][z]=sum;
	return val[x][y1][z]%m;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	cin>>n>>m>>b>>mod;
	for(int i=0;i<n;i++){
		cin>>cost[i];
	}
	memset(val,-1,sizeof(val));
	int ans = dp(0,m,b);
	cout<<ans<<endl;
}