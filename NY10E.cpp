#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	LL dp[10][65];
	for(LL i=0;i<10;i++){dp[i][1] = 10-i;}
	for(LL i=2;i<65;i++){
		dp[9][i] = dp[9][i-1];
		for(LL j=8;j>=0;j--){
			dp[j][i] = dp[j][i-1]+dp[j+1][i];
		}
		//for(LL j=0;j<10;j++){cout<<dp[j][i]<<" ";}cout<<endl;
	}
	while(t--){
		LL p,n;
		cin>>p>>n;

		cout<<p<<" "<<dp[0][n]<<endl;
	}
}