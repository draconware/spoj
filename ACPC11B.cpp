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
		int n;
		cin>>n;

		set<int> s1,s2;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			s1.insert(x);
		}
		int m;cin>>m;
		for(int i=0;i<m;i++){
			int x;cin>>x;
			s2.insert(x);
		}

		int ans=INT_MAX;
		set<int>::iterator it = s1.begin();
		for(;it!=s1.end();it++){
			set<int>::iterator it1 = upper_bound(s2.begin(),s2.end(),*it);
			if(it1 != s2.end()){
				ans = min(ans,abs(*it1 - *it));
			}
			if(it1 != s2.begin()){
				it1--;
				ans = min(ans,abs(*it1 - *it));
			}
		}
		cout<<ans<<endl;
	}
}