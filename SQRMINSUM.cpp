#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		vector<int> v(n+1,1);
		int x = n;
		while(m--){
			int val = (int)floor(sqrt(x));
			v[val]++;
			v[x]--;

			while(v[x] == 0){
				x = x-1;
			}
		}
		int ans=0;
		for(int i=1;i<=x;i++){
			ans += i*v[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}