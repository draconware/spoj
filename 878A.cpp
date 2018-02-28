#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;cin>>n;
	int s[n],d[n];
	for(int i=0;i<n;i++){cin>>s[i]>>d[i];}

	int ans = s[0];
	for(int i=1;i<n;i++){
		int x = s[i];
		while(x<=ans){
			x+=d[i];
		}
		ans = x;
	}
	cout<<ans<<endl;
}