#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int x=2,y=1;
	for(int i=2;i<=n;i++){
		int temp=x;
		x = 2*x - y;
		y = temp-y;
	}
	cout<<x<<endl;
}