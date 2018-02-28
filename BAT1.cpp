#include<bits/stdc++.h>
using namespace std;

int n,m;
int open[29];
int money[29][29],power[29][29];
int dp[29][29][1009];

int f(int i,int j,int k){
	//cout<<i<<","<<j<<","<<k<<endl;
	if(k==0){return 0;}
	if(i>n || j>m){return 0;}
	if(dp[i][j][k]!=-1){return dp[i][j][k];}

	int sum = 0;
	if(j==0){
		sum = max(f(i,j+1,k-open[i]),f(i+1,j,k));
	}else{
		int a=k,b=0;
		while(a>=0){
			sum = max(sum,b+f(i,j+1,a));
			sum = max(sum,b+f(i+1,0,a));
			a-=money[i][j];
			b+=power[i][j];
		}
	}
	dp[i][j][k] = sum;
	return sum;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		cin>>n>>m;
		int k;cin>>k;

		for(int i=1;i<=n;i++){
			cin>>open[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>money[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>power[i][j];
			}
		}
		memset(dp,-1,sizeof(dp));
		int ans = max(0,f(1,0,k));
		cout<<ans<<endl;
	}
}