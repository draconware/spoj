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
		int n,m;
		cin>>n>>m;
		int arr[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;cin>>c;
				if(c=='#'){arr[i][j]=0;}
				if(c=='0'){arr[i][j]=1;}
				if(c=='T'){arr[i][j]=2;}
			}
		}
		//cout<<"executed"<<endl;
		int dp[2][n+2][m+2];
		memset(dp,0,sizeof(dp));

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(arr[i][j]>0){dp[0][i][j] = max(dp[1][i-1][j],dp[0][i][j-1])+arr[i][j]-1;}
			}
			for(int j=m;j>0;j--){
				if(arr[i][j]>0){dp[1][i][j] = max(dp[0][i-1][j],dp[1][i][j+1])+arr[i][j]-1;}
			}
			for(int j=1;j<=m;j++){cout<<dp[1][i][j]<<" ";}cout<<endl;
		}
		cout<<dp[1][n][m]<<endl;
	}
}