#include<bits/stdc++.h>
using namespace std;

int n;
long long dp[30][20];

long long f(char c,int x){
	//cout<<c<<" "<<x<<endl;
	if(x==n-1){return 1;}
	if(dp[c-'a'][x]!=-1){return dp[c-'a'][x];}
	int i=c-'a';
	long long sum=0;
	for(int j=0;j<=i+1;j++){
		sum += (f(max(c-'a',j)+'a',x+1));
	}
	dp[c-'a'][x]=sum;
	return dp[c-'a'][x];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		cin>>n;
		memset(dp,-1,sizeof(dp));

		long long ans = f('a',0);
		cout<<ans<<endl;
	}
}