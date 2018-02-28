#include<bits/stdc++.h>
using namespace std;

int val[15][40][40];

int main(){
	int t;
	cin>>t;

	memset(val,0,sizeof(val));
	val[20][20][0]=1;
	for(int k=1;k<=14;k++){
		for(int i=1;i<40;i++){
			for(int j=1;j<40;j++){
				dp[i][j][k] = dp[i-1][j-1][k-1]+dp[i-1][j+1][k-1]+dp[i-1][j][k-1]+dp[i+1][j-1][k-1]+dp[i+1][j][k-1]+dp[i+1][j+1][k-1];				
			}
		}
	}

	while(t--){
		int n;
		cin>>n;

		if(n<=1){cout<<"0"<<endl;}
		else{
			cout<<dp[20][20][n];
		}
	}
}