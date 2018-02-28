#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,v1,v2,t1,t2;
	cin>>n>>v1>>v2>>t1>>t2;

	int ans1 = 2*t1+v1*n;
	int ans2 = 2*t2+v2*n;

	if(ans1 > ans2){
		cout<<"second"<<endl;
	}else if(ans1 == ans2){
		cout<<"draw"<<endl;
	}else{
		cout<<"first"<<endl;
	}
}