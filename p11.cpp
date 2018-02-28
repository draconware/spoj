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

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}

	int ans=0;
	for(int i=0;i<n-1;i++){
		if(arr[i]<arr[i+1]){ans++;arr[i]=arr[i+1];}
	}
	cout<<ans<<endl;
}