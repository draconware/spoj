#include<bits/stdc++.h>
using namespace std;

int arr[209],n;
int dp[209][209][209];

int f(int s,int w,int b){
	if(s>n){return 0;}
	if(dp[s][w][b] != -1){return dp[s][w][b];}

	int  sum=INT_MAX;
	if(arr[s]>arr[w] || w==0){sum=min(sum,f(s+1,s,b));}
	if(arr[s]<arr[b] || b==0){sum=min(sum,f(s+1,w,s));}
	dp[s][w][b] = min(sum,1+f(s+1,w,b));
	return dp[s][w][b];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(1){
		cin>>n;
		if(n==-1){return 0;}

		arr[0]=0;
		for(int i=1;i<=n;i++){cin>>arr[i];}
		memset(dp,-1,sizeof(dp));
		int ans = f(1,0,0);
		cout<<ans<<endl;
	}
}