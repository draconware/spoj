#include<bits/stdc++.h>
using namespace std;

#define INF 10000000

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s,v;
	cin>>s>>v;

	int n,m;
	n = s.length();
	m = v.length();

	int k[n+1][m+1];
	for(int i=0;i<n;i++){
		int x = -1;
		for(int j=0;j<m;j++){
			if(s[i]==v[j]){x=j;}
			k[i+1][j+1] = x;
		}
	}	
	int dp[n+1][m+1];
	for(int i=1;i<=n;i++){dp[i][0]=1;}
	for(int i=0;i<=m;i++){
		dp[0][i] = INF;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(k[i][j]==-1){dp[i][j]=1;}
			else{
				dp[i][j] = min(1+dp[i-1][k[i][j]],dp[i-1][j]);
			}
		}
	}
	cout<<dp[n][m]<<endl;
}