#include<bits/stdc++.h>
using namespace std;

#define M 761238923

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	while(1){
		int n;
		cin>>n;

		if(n==0){return 0;}
		if(n==1){cout<<"1"<<endl;}
		else{
			int dp[n+1][n+1];
			memset(dp,0,sizeof(dp));
			dp[1][0]=dp[1][1]=1;
			for(int i=2;i<n;i++){
				for(int j=0;j<=i;j++){
					dp[i][j]=0;
					for(int k=0;k<=j;k++){
						dp[i][j] = (dp[i][j] + dp[i-1][j-k])%M;
					}
				}
			}
			dp[n][n]=0;
			for(int k=0;k<=n;k++){
				dp[n][n] = (dp[n][n] + dp[n-1][n-k])%M;
			}
			cout<<dp[n][n]<<endl;
		}
	}
	return 0;
}