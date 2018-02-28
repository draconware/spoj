#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL dp[10001][5001];

LL MAX = 1e12;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n;
	cin>>n;

	LL c[n+1],a[n+1];
	for(int i=1;i<=n;i++){cin>>c[i]>>a[i];}
	for(int i=0;i<10001;i++){for(int j=0;j<5001;j++){dp[i][j]=MAX;}}

	dp[1][0]=a[1];
	for(int i=2;i<n;i++){
		for(int j=0;j<=i/2;j++){
			if(j-1>=0){dp[i][j] = min(dp[i-1][j-1]+c[i],dp[i][j]);}
			if(i-1-j>=j){dp[i][j] = min(dp[i][j],dp[i-1][j]+a[i]);}
		}
	}
	cout<<dp[n-1][n/2 -1]+c[n]<<endl;
}