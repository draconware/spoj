#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL MAX = (LL)1e15;
LL dp[5001][5001];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	vector<LL> b(n+1),c(m+1);
	for(int i=1;i<=n;i++){cin>>b[i];}
	for(int i=1;i<=m;i++){cin>>c[i];}
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());

	for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){dp[i][j]=MAX;}}

	dp[1][1]=abs(b[1]-c[1]);
	for(int i=2;i<=m;i++){
		dp[1][i] = min(abs(b[1]-c[i]),dp[1][i-1]);
	}
	for(int i=2;i<=n;i++){
		for(int j=i;j<=m;j++){
			dp[i][j] = min(dp[i-1][j-1]+abs(b[i]-c[j]),dp[i][j-1]);
		}
	}
	cout<<dp[n][m]<<endl;
}