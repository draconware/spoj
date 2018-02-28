#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m,x,y;
	cin>>n>>m>>x>>y;

	int arr[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	int z = arr[x][y];
	arr[x-1][y-1]=0;
	int dp[n+1][m+1];
	for(int i=0;i<n+1;i++){for(int j=0;j<m+1;j++){dp[i][j]=INT_MAX;}}

	dp[x][y]=0;
	for(int i=x;i<=n;i++){
		for(int j=y;j<=m;j++){
			if(i==x && j==y){continue;}
			dp[i][j] = min(dp[i][j-1],dp[i-1][j]);
			dp[i][j]+=arr[i][j];
		}
	}
	//for(int i=x;i<=n;i++){for(int j=y;j<=m;j++){cout<<dp[i][j]<<" ";}cout<<endl;}
	if(z-dp[n][m]>=0){cout<<"Y "<<z-dp[n][m]<<endl;}
	else{cout<<"N"<<endl;}
}