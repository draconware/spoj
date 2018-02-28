#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	scanf("%d", &n);
	char s[n],t[n];
	scanf("%s", s);
	for(int i=0;i<n;i++){t[i]=s[n-1-i];}

	int dp[2][n+1];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1] == t[j-1]){dp[i%2][j] = dp[(i-1)%2][j-1]+1;}
			else{dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]);}
		}
	}
	cout<<n-dp[n%2][n]<<endl;
}