#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	n*=8;
	vector<int> v(k);
	bool flag=true;
	for(int i=0;i<k;i++){cin>>v[i];}
	for(int i=0;i<k;i++){
		n-=(v[i]/4)*4;
		v[i]-=(v[i]/4)*4;
	}
	for(int i=0;i<k;i++){
		n-=(v[i]/2)*2;
		v[i]-=(v[i]/2)*2;
	}
	for(int i=0;i<k;i++){
		n-=v[i];
		v[i]-=1;
	}
	if(n<0){flag=false;}
	else{
		for(int i=0;i<k;i++){
			if(v[i]!=0){flag=false;break;}
		}
	}
	if(flag){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}