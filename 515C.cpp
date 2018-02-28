#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	string s;
	cin>>s;
	int arr[10];
	arr[2]=2;arr[3]=3;
	arr[4]=322;arr[5]=5;
	arr[6]=53;arr[7]=7;
	arr[8]=7222;arr[9]=7332;

	vector<int> v;
	for(int i=0;i<n;i++){
		if(s[i]>'1'){
			int x = arr[s[i]-'0'];
			while(x>0){v.push_back(x%10);x/=10;}
		}
	}
	sort(v.begin(),v.end());
	n=v.size();
	for(int i=n-1;i>=0;i--){cout<<v[i];}cout<<endl;
}