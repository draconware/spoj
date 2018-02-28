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

	while(t--){
		int n;
		cin>>n;

		vector<pair<pair<LL,LL>,LL> > v;
		for(int i=0;i<n;i++){
			LL x,y,z;
			cin>>x>>y>>z;
			v.push_back(make_pair(make_pair(y+x,x),z));
		}
		sort(v.begin(),v.end());
		vector<LL> s(n),f(n),cost(n);
		for(int i=0;i<n;i++){
			f[i] = v[i].first.first;
			s[i] = v[i].first.second;
			cost[i] = v[i].second;
			//cout<<f[i]<<" "<<s[i]<<" "<<cost[i]<<endl;
		}
		LL val[n];
		val[0] = cost[0];
		for(int i=1;i<n;i++){
			vector<LL>::iterator it = upper_bound(f.begin(),f.end(),s[i]);
			LL x = cost[i];
			if(it != f.begin()){
				it--;
				int j = it-f.begin();
				while(j>0 && f[j]==s[i]){j--;}
				if(f[j] != s[i]){
					x += val[j];
				}
			}
			val[i] = max(val[i-1],x);
			//cout<<val[i]<<" ";
		}
		cout<<val[n-1]<<endl;
	}
	return 0;
}