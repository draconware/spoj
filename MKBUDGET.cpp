#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL n,pay,emp,sev;
LL arr[30];
LL dp[30][35];

LL f(LL s,LL x){
	if(s>n){return 0;}
	if(dp[s][x]!=-1){return dp[s][x];}

	LL sum = (LL)1e18;
	for(LL i=arr[s];i<=30;i++){
		if(i<=x){
			sum = min(sum,i*pay + (x-i)*sev + f(s+1,i));
		}else{
			sum = min(sum,i*pay + (i-x)*emp + f(s+1,i));
		}
	}
	dp[s][x] = sum;
	return sum;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int c = 1;
	while(1){
		cin>>n>>emp>>pay>>sev;
		if(n==0){break;}

		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}

		LL ans = (LL)1e18;
		memset(dp,-1,sizeof(dp));

		for(LL i=arr[1];i<=30;i++){
			ans = min(ans,i*(pay + emp)+f(2,i));
		}
		cout<<"Case "<<c<<", cost = $"<<ans<<endl;
		c++;
	}
}