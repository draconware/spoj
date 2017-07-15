#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<pair<int,int> > v(n),cost(n);
		for(int i=0;i<n;i++){
			cin>>v[i].first;
		}

		long long sum=0;
		for(int i=0;i<n;i++){
			cin>>v[i].second;
			sum+=v[i].second;
		}
		sort(v.begin(),v.end());

		for(int i=0;i<n;i++){
			//cout<<"for building --> "<<v[i].first<<" cost is --> "<<v[i].second<<endl;
		}
		int mark;
		long long val=0;
		for(int i=0;i<n;i++){
			val+=(v[i].second);
			if(val >= (sum/2 + sum%2)){
				mark=v[i].first;
				//cout<<"mark is --> "<<mark<<endl;
				break;
			}
		}
		long long ans=0;

		for(int i=0;i<n;i++){
			ans+=((abs(v[i].first - mark))*v[i].second) ;
		}

		cout<<ans<<endl;
	}
	return 0;
}
