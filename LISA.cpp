#include<bits/stdc++.h>
using namespace std;

#define LL long long
string s;
int n;

LL MIN=-1,INI=0,MAX=LONG_MAX;
LL val[109][109];

LL dpmax(int l,int h){
	if(l==h){LL r = (s[l-1]-'0');return r;}
	if(val[l][h] != MIN){return val[l][h];}

	LL res=INI;
	for(int i=l;i<h;i+=2){
		if(s[i] == '+'){
			res = max(res,dpmax(l,i)+dpmax(i+2,h));
		}
		if(s[i] == '*'){
			res = max(res,dpmax(l,i) * dpmax(i+2,h));
		}
	}
	val[l][h]=res;
	return val[l][h];
}

LL dpmin(int l,int h){
	if(l==h){LL r = (s[l-1]-'0');return r;}
	if(val[l][h] != MIN){return val[l][h];}

	LL res=MAX;
	for(int i=l;i<h;i+=2){
		if(s[i] == '+'){
			res = min(res,dpmin(l,i)+dpmin(i+2,h));
		}
		if(s[i] == '*'){
			res = min(res,dpmin(l,i) * dpmin(i+2,h));
		}
	}
	val[l][h]=res;
	return val[l][h];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		cin>>s;
		n = s.length();
		memset(val,MIN,sizeof(val));
		LL ans = dpmax(1,n);
		
		memset(val,MIN,sizeof(val));
		LL ans1 = dpmin(1,n);
		cout<<ans<<" "<<ans1<<endl;
	}
	return 0;
}