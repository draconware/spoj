#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif	

	int t,c=0;
	cin>>t;

	while(t--){
		c++;
		int n,k;
		cin>>n>>k;

		int arr[n+2];
		for(int i=2;i<=n+1;i++){cin>>arr[i];}

		int dp[k+1][n+2];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=k;i++){
			for(int j=2;j<=n+1;j++){
				if(arr[j] <= i){dp[i][j] = max(dp[i][j-1],dp[i-arr[j]][j-2]+arr[j]);}
				else{dp[i][j] = dp[i][j-1];}
				//cout<<i<<" "<<j-1<<" "<<dp[i][j]<<endl;
			}
		}
		cout<<"Scenario #"<<c<<": "<<dp[k][n+1]<<endl;
	}
	return 0;
}