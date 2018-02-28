#include<bits/stdc++.h>
using namespace std;

int MAX = 1000000000;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif


	while(1){
		int n,t;
		cin>>n>>t;
		if(n==0 && t==0){return 0;}

		int travel[n][n];
		for(int i=0;i<n;i++){for(int j=0;j<n;j++){cin>>travel[i][j];}}
		int toll[n][n];
		for(int i=0;i<n;i++){for(int j=0;j<n;j++){cin>>toll[i][j];}}
		//for(int i=0;i<n;i++){for(int j=0;j<n;j++){cout<<}}

		int dp[t+1][n];
		for(int i=0;i<=t;i++){for(int j=0;j<n;j++){dp[i][j]=MAX;}}
		dp[0][0]=0;

		int besttime=MAX,besttoll=MAX;
		for(int i=0;i<=t;i++){
			for(int j=0;j<n;j++){
				if(dp[i][j]>=MAX){continue;}
				if(i<t){dp[i+1][j] = min(dp[i+1][j],dp[i][j]);}

				for(int k=0;k<n;k++){
					if(i+travel[j][k] <= t){
						int x = i+travel[j][k];
						dp[x][k] = min(dp[x][k],dp[i][j]+toll[j][k]);
					}
				}
			}
			if(dp[i][n-1] < besttoll){
				besttoll = dp[i][n-1];
				besttime = i;
			}
		}
		cout<<besttoll<<" "<<besttime<<endl;
	}
}