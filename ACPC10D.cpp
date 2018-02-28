#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL MAX = (LL)1e18;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int c=0;
	while(1){
		c++;
		int n;
		cin>>n;
		if(n==0){return 0;}

		LL arr[n+1][4];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>arr[i][j];
			}
		}
		LL dp[n+1][5];
		for(int i=0;i<=n;i++){for(int j=0;j<5;j++){dp[i][j] = MAX;}}

		dp[1][2] = arr[1][2];dp[1][3] = arr[1][2]+arr[1][3];
		for(int i=2;i<=n;i++){
			for(int j=1;j<4;j++){
				dp[i][j] = min(dp[i][j-1],min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1])));
				dp[i][j]+=arr[i][j];
			}
		}
		cout<<c<<". "<<dp[n][2]<<endl;
	}
}