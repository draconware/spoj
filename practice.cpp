#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	map<int,int> m;
	for(int i=1;i<=10;i++){
		m.insert(i);
	}
	for(int i=0;i<n;i++){
		cout<<m[i]<<" ";
	}
	cout<<endl;
}