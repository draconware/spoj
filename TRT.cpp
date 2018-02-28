#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL arr[2000+9];
LL val[2009][2009];
int n;

LL dp(int i,int j){
	//cout<<i<<" "<<j<<endl;
	if(i>j){return 0;}
	LL y = (LL)(n-j+i);
	if(i==j){return arr[i]*y;}
	if(val[i][j] != -1){return val[i][j];}

	val[i][j] = max(dp(i+1,j)+arr[i]*y,dp(i,j-1)+arr[j]*y);
	return val[i][j];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	memset(val,-1,sizeof(val));
	long long ans = dp(1,n);
	cout<<ans<<endl;
}