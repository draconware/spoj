#include<bits/stdc++.h>
using namespace std;

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
		int n,m;
		cin>>n>>m;

		int arr[n][m];
		for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>arr[i][j];}}

		int dp[n][m];
		//memset(dp,1,sizeof(dp));
		dp[n-1][m-1]=1;
		for(int i=m-2;i>=0;i--){dp[n-1][i] = dp[n-1][i+1]-arr[n-1][i];if(dp[n-1][i]<=0){dp[n-1][i]=1;}}
		for(int i=n-2;i>=0;i--){dp[i][m-1] = dp[i+1][m-1]-arr[i][m-1];if(dp[i][m-1]<=0){dp[i][m-1]=1;}}

		for(int i=n-2;i>=0;i--){
			for(int j=m-2;j>=0;j--){
				dp[i][j] = min(dp[i+1][j],dp[i][j+1])-arr[i][j];
				if(dp[i][j]<=0){dp[i][j]=1;}
			}
		}
		cout<<dp[0][0]<<endl;
	}
}