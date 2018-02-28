#include<bits/stdc++.h>
using namespace std;

int f(int n,int k){
	if(n==1){return 1;}
	return (f(n-1,k+1)+k-1)%n +1;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int ans = f(n,1);
		cout<<ans<<endl;
	}
}