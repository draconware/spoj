#include<bits/stdc++.h>
using namespace std;

string s;
int val[30],n;

int dp(int i,int x){
	if(i>=n){return 1;}
	if(val[i]!= 0){return val[i];}

	if(x!=0){
		if(i+2<n){
			int y = (s[i]-'0')*10 + (s[i+1]-'0');
			if(y<=20 && y>=0){
				val[i]+=dp(i+2,s[i+2]-'0');
			} 
		}else if(i+2 == n){
			int y = (s[i]-'0')*10 + (s[i+1]-'0');
			if(y<=20 && y>=0){
				val[i]+=dp(i+2,100);
			} 
		}
		if(i+1<n){
			val[i]+=dp(i+1,s[i+1]-'0');
		}else if(i+1 == n){
			val[i]+=dp(i+1,100);
		}
	}else{
		if(i+1<n){
			val[i]+=dp(i+1,s[i+1]-'0');
		}else if(i+1==n){
			val[i]+=dp(i+1,100);
		}
	}
	return val[i];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	cin>>s;n=s.length();
	memset(val,0,sizeof(val));
	cout<<dp(0,s[0]-'0')<<endl;
}