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

		int arr1[n],arr2[n];
		for(int i=0;i<n;i++){cin>>arr1[i];}
		for(int i=0;i<n;i++){cin>>arr2[i];}

		vector<pair<int,int> > v;
		for(int i=0;i<n;i++){v.push_back(make_pair(arr1[i],arr2[i]));}
		sort(v.begin(),v.end());

		int res[n];
		for(int i=0;i<n;i++){res[i] = v[i].second;}		
		int lis[n];
		for(int i=0;i<n;i++){lis[i]=1;}

		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(res[j]<=res[i]){
					lis[i]=max(lis[i],lis[j]+1);
				}
			}
		}
		int ans=1;
		for(int i=0;i<n;i++){ans = max(lis[i],ans);}
		cout<<ans<<endl;
	}
}