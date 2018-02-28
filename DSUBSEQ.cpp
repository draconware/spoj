#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		int n = s.length();
		int dp[n+9],last[30];
		memset(dp,0,sizeof(dp));
		memset(last,0,sizeof(last));

		dp[0]=1;
		for(int i=1;i<=n;i++){
			dp[i] = (dp[i-1]*2)%M;
			if(last[s[i-1]-'A'] != 0){
				dp[i] = (dp[i] - dp[last[s[i-1]-'A']-1] + M)%M;
			}
			last[s[i-1]-'A']=i;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}