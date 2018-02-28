#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[n+1];
	for(int i=1;i<=n;i++){cin>>arr[i];}

	int dp[n+1];
	for(int i=0;i<=n;i++){dp[i]=1;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(arr[j]<arr[i]){dp[i] = max(dp[i],dp[j]+1);}
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){ans = max(ans,dp[i]);}
	cout<<ans<<endl;
}