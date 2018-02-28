#include<bits/stdc++.h>
using namespace std;

string s;
int n;
int arr[5009];

int dp(int i){
	if(i>=n){return 1;}
	if(arr[i]!=0){return arr[i];}
	bool flag=false;
	if((s[i]-'0')>=1 && (s[i]-'0')<=9){
		arr[i]+=dp(i+1);
		flag=true;
	}
	if(i+1<n && flag){
		if((s[i]-'0')*10 + (s[i+1]-'0')<=26 && (s[i]-'0')*10 + (s[i+1]-'0')>=1){
			arr[i]+=dp(i+2);
		}
	}
	return arr[i];
}

int main(){
	
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif
	
	while(1){
		cin>>s;
		if(s == "0"){return 0;}
		n = s.length();
		memset(arr,0,sizeof(arr));
		cout<<dp(0)<<endl;
	}
	return 0;
}