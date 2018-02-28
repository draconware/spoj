#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		string s;
		cin>>s;

		int ones[n+1],zeros[n+1];
		memset(ones,0,sizeof(ones));
		memset(zeros,0,sizeof(zeros));

		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'){ones[i] = ones[i-1]+1;zeros[i]=zeros[i-1];}
			else{zeros[i] = zeros[i-1]+1;ones[i]=ones[i-1];}
		}
		//for(int i=1;i<=n;i++){cout<<ones[i]<<","<<zeros[i]<<" ";}cout<<endl;
		int dp[n+1][n+1];
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'){dp[i][i]=1;}
			else{dp[i][i]=0;}
		}
		for(int l=2;l<=n;l++){
			for(int i=1;i<=n-l+1;i++){
				int j=l+i-1;
				if(ones[j]-ones[i-1] > zeros[j]-zeros[i-1]){dp[i][j] = j-i+1;}
				else{
					dp[i][j]=0;
					for(int k=i;k<j;k++){
						dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
					}
				}
			}
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
}