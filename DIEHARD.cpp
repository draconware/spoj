#include<bits/stdc++.h>
using namespace std;

int dp[2][1009][1009];

int solve(int p,int x,int y){
	//cout<<p<<" "<<x<<" "<<y<<endl;
	//if(x==0 || y==0){return 0;}
	int sum=0;
	if(dp[p][x][y] != -1){return dp[p][x][y];}
	if(p==0){sum = 1+solve(1-p,x+3,y+2);}
	else{
		if(x>5 && y>10){sum = max(sum,1+solve(1-p,x-5,y-10));}
		if(x>20){sum = max(sum,1+solve(1-p,x-20,y+5));}
	}
	dp[p][x][y]=sum;
	return sum;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	memset(dp,-1,sizeof(dp));

	while(t--){
		int h,a;
		cin>>h>>a;
		//cout<<dp[1][1][1]<<endl;
		int ans = solve(0,h,a);
		cout<<ans<<endl;
	}
	return 0;
}