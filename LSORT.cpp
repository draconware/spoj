#include<bits/stdc++.h>
using namespace std;

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
		int n;
		cin>>n;

		int arr[n];
		for(int i=0;i<n;i++){cin>>arr[i];}

		int p[n];
		for(int i=0;i<n;i++){
			p[arr[i]-1]=i;
		}	
		int x1[n][n],x2[n][n];
		for(int i=0;i<n;i++){
			x1[i][i]=p[i];
			for(int j=i+1;j<n;j++){
				x1[i][j] = x1[i][j-1] - ((p[j]>p[i])?0:1);
			}
		}
		for(int i=0;i<n;i++){
			x2[i][i]=p[i];
			for(int j=i-1;j>=0;j--){
				x2[i][j] = x2[i][j+1] - ((p[j]>p[i])?0:1); 
			}
		}
		int dp[n][n];
		for(int i=0;i<n;i++){
			dp[i][i]=p[i]+1;
		}
		for(int p=1;p<n;p++){
			for(int i=0;i+p<n;i++){
				int k=p+1;
				int j=p+i;
				dp[i][j] = min(dp[i][j-1]+(x2[j][i]+1)*k,dp[i+1][j]+(x1[i][j]+1)*k);
			}
		}
		cout<<dp[0][n-1]<<endl;
	}
}