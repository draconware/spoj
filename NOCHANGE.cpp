#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int x,k;
	cin>>x>>k;

	vector<int> v(k+1);
	v[0]=0;
	for(int i=1;i<=k;i++){
		cin>>v[i];
		v[i]+=v[i-1];
	}

	bool ans[x+1];
	memset(ans,0,sizeof(ans));
	ans[0]=1;
	for(int i=1;i<=k;i++){
		for(int j=v[i];j<=x;j++){
			ans[j]|=ans[j-v[i]];
		}
	}
	if(ans[x]){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}