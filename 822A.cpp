#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;

	int c = min(a,b);
	int ans=1;
	for(int i=2;i<=c;i++){ans*=i;}
	cout<<ans<<endl;
}