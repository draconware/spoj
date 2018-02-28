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
		int arr1[n+1][m+1];
		memset(arr1,0,sizeof(arr1));
		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>arr1[i][j];}}
		int arr2[n+1][m+1];
		memset(arr2,0,sizeof(arr2));
		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>arr2[i][j];}}
		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){arr1[i][j]+=arr1[i][j-1];}}
		for(int i=1;i<=m;i++){for(int j=1;j<=n;j++){arr2[j][i]+=arr2[j-1][i];}}

		int dp[n+1][m+1];
		memset(dp,0,sizeof(dp));

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j] = max(arr2[i][j]+dp[i][j-1],arr1[i][j]+dp[i-1][j]);
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}