#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;string s;
	cin>>n>>s;

	int curr;
	vector<int> v;
	for(int i=0;i < (int)s.size();i++){
		curr+=(s[i]-'0');
		v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end());
	if(curr>=n){cout<<"0"<<endl;}
	else{
		int ans=0;
		for(int i=0;i < (int)v.size();i++){
			curr+=(9-v[i]);ans++;
			if(curr>=n){break;}
		}
		cout<<ans<<endl;
	}
}