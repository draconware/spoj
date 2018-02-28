#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		long long sum1=0,sum2=0,x,n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){cin>>x;sum1+=x;}
		for(int i=0;i<m;i++){cin>>x;sum2+=x;}

		if(sum1>=sum2){cout<<"Snow"<<endl;}
		else{cout<<"Death"<<endl;}
	}
}