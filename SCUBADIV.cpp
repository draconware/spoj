#include<bits/stdc++.h>
using namespace std;

int MAX = 1000000000;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		int a,b,n;
		cin>>a>>b>>n;

		int o2[n+1],n2[n+1],w[n+1];
		for(int i=1;i<=n;i++){cin>>o2[i]>>n2[i]>>w[i];}
		//for(int i=1;i<=n;i++){cout<<w[i]<<" ";}cout<<endl;

		int dp[n+1][a+1][b+1];
		for(int i=0;i<=a;i++){
			for(int j=0;j<=b;j++){
				dp[0][i][j]=MAX;
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=0;j<=a;j++){
				for(int k=0;k<=b;k++){
					if(j<=o2[i] && k<=n2[i]){dp[i][j][k] = min(dp[i-1][j][k],w[i]);}
					else if(j<=o2[i]){dp[i][j][k] = min(dp[i-1][j][k],dp[i-1][j][k-n2[i]]+w[i]);}
					else if(k<=n2[i]){dp[i][j][k] = min(dp[i-1][j][k],dp[i-1][j-o2[i]][k]+w[i]);}
					else{dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-o2[i]][k-n2[i]]+w[i]);}
					//cout<<i<<" "<<j<<" "<<k<<"---- "<<dp[i][j][k]<<endl;
				}
			}
		}
		cout<<dp[n][a][b]<<endl;
	}
	return 0;
}