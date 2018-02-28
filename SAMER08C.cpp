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

		int dp[n+9][m+9],arr[n+9][m+9];
		memset(dp,0,sizeof(dp));
		memset(arr,0,sizeof(arr));

		for(int i=2;i<=n+1;i++){
			for(int j=2;j<=m+1;j++){
				cin>>arr[i][j];
			}
		}
		for(int i=2;i<=n+1;i++){
			for(int j=2;j<=m+1;j++){
				dp[i][j] = max(dp[i][j-2]+arr[i][j],dp[i][j-1]);
			}
			for(int j=2;j<=m+1;j++){
				dp[i][j] += dp[i-2][m+1];
			}
			if(dp[i][m+1] < dp[i-1][m+1]){
				for(int j=2;j<=m+1;j++){
					dp[i][j]=dp[i-1][m+1];
				}
			}
		}
		cout<<dp[n+1][m+1]<<endl;
	}
}