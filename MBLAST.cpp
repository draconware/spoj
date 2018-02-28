#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int x,n,m;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	cin>>s1>>s2;
	cin>>x;

	n = s1.length();
	m = s2.length();

	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		dp[i][0] = x*i;
	}
	for(int j=0;j<=m;j++){
		dp[0][j] = x*j;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = min(dp[i-1][j-1]+abs(s1[i-1]-s2[j-1]),x+min(dp[i-1][j],dp[i][j-1]));
		}
	}
	cout<<dp[n][m]<<endl;
}