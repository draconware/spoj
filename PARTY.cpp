#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(1){
		int budget,n;
		cin>>budget>>n;
		if(n==0 && budget==0){return 0;}
		int a[n+1],b[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}

		int dp[n+1][budget+1];
		memset(dp,0,sizeof(dp));
		//for(int i=0;i<=budget;i++){dp[0][i]=0;}

		for(int i=1;i<=n;i++){
			for(int j=0;j<=budget;j++){
				if(j-a[i]<0){dp[i][j] = max(dp[i][j],dp[i-1][j]);}
				else{dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i]]+b[i]);}
				//cout<<dp[i][j]<<" ";
			}
			//cout<<endl;
		}
		int ans1=-1,ans2=-1;
		for(int i=0;i<=budget;i++){
			if(dp[n][i] > ans1){
				ans1=dp[n][i];ans2=i;
			}
		}
		cout<<ans2<<" "<<ans1<<endl;
	}
}