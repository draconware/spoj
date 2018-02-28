#include<bits/stdc++.h>
using namespace std;

int val[1000009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int k,l,m;
	cin>>k>>l>>m;

	int arr[m],c=0;
	for(int i=0;i<m;i++){
		cin>>arr[i];
		c = max(c,arr[i]);
	}
	val[1]=1;val[0]=0;
	for(int i=2;i<=c;i++){
		int x=val[i-1];

		if(i>=k){x = min(x,val[i-k]);}
		if(i>=l){x = min(x,val[i-l]);}
		val[i]=1-x;
	}
	for(int i=0;i<m;i++){
		if(val[arr[i]] == 1){cout<<"A";}
		else{cout<<"B";}
	}
	cout<<endl;
}