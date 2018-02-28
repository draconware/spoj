#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL mod = 1e9;

string s;
bool vis[209][209];
LL dp[209][209];

bool chk(int i,int j){
	if(s[i]=='(' && s[j]==')'){return true;}
	if(s[i]=='(' && s[j]=='?'){return true;}
	if(s[i]=='?' && s[j]==')'){return true;}

	if(s[i]=='{' && s[j]=='}'){return true;}
	if(s[i]=='{' && s[j]=='?'){return true;}
	if(s[i]=='?' && s[j]=='}'){return true;}

	if(s[i]=='[' && s[j]==']'){return true;}
	if(s[i]=='[' && s[j]=='?'){return true;}
	if(s[i]=='?' && s[j]==']'){return true;}
	return false;
}

LL f(int l,int r){
	if(l>r){return 1;}
	if(vis[l][r]){return dp[l][r];}

	vis[l][r] = true;
	LL sum=0;
	for(int i=l+1;i<=r;i+=2){
		if(chk(l,i)){
			sum = (sum + ((f(l+1,i-1)%mod)*(f(i+1,r)%mod))%mod)%mod;
		}else if(s[i]=='?' && s[l]=='?'){
			sum = (sum + (3*((f(l+1,i-1)%mod)*(f(i+1,r)%mod))%mod)%mod);
		}
	}
	dp[l][r] = sum;
	return dp[l][r];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n>>s;

	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));

	LL ans = f(0,n-1);
	//cout<<ans<<endl;
	vector<int> res;
	
	while(ans>0 && (res.size()<5)){
		res.push_back(ans%10);ans/=10;
	}

	n = res.size();
	if(n>0){for(int i=n-1;i>=0;i--){cout<<res[i];}cout<<endl;}
}