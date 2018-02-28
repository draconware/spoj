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
		int n,k;
		cin>>n>>k;

		string s;
		cin>>s;
		int arr[n];
		vector<int> v;
		for(int i=0;i<n;i++){arr[i]=s[i]-'0';}
		v.push_back(arr[0]);
		for(int i=1;i<n;i++){
			v.push_back(v[i-1]+arr[i]);
		}

		long long ans=0;
		vector<int>::iterator it = v.begin();
		for(int i=0;i<n;i++,it++){
			if(arr[i]>k){continue;}
			if(binary_search(v.begin()+i,v.end(),v[i]+(k-arr[i]))){
				int x = lower_bound(v.begin()+i,v.end(),v[i]+(k-arr[i])) - (v.begin() + i);
				int y = upper_bound(v.begin()+i,v.end(),v[i]+(k-arr[i])) - (v.begin() + i);
				//cout<<i<<" "<<x<<" "<<y<<endl;
				ans = ans + (long long)(y-x);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}