#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<int> v[30];
LL sum[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[26];
	for(int i=0;i<26;i++){cin>>arr[i];}
	//for(int i=0;i<26;i++){cout<<arr[i]<<" ";}cout<<endl;

	string s;
	cin>>s;

	int n = (int)s.length();
	LL x=0;
	for(int i=0;i<n;i++){
		x+=arr[s[i]-'a'];
		v[s[i]-'a'].push_back(i);
		sum[i]=x;
	}
	
	LL ans=0;
	for(int i=0;i<26;i++){
		map<long long,int> m;
		for(int j=0;j<(int)v[i].size();j++){
			int p = v[i][j];
			ans += m[sum[p-1]];
			m[sum[p]]++;
		}
	}
	cout<<ans<<endl;
}