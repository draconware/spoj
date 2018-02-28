#include<bits/stdc++.h>
using namespace std;

string s;
int n;

bool check(int i){
	int st=i,e=n-1+i;
	while(st<=e){
		//cout<<s[st]<<" "<<s[e]<<endl;
		if(s[st] != s[e]){return false;}
		st++;e--;
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int m,ans=0;
	cin>>n;
	cin>>s;m=s.length();
	//cout<<s<<endl;
	for(int i=0;i<=(m-n);i++){
		//cout<<"processing on--- "<<i<<" ----"<<endl;
		if(check(i)){ans++;}
	}
	cout<<ans<<endl;
}
