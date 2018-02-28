#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int val[1009][1009];

int dp(int s,int e){
	if(e-s <= 1){return max(v[e],v[s]);}
	if(val[s][e] != -1){return val[s][e];}

	int x,y;
	x=s+1,y=e;
	if(v[x]<v[y]){val[s][e] = max(val[s][e],v[s]+dp(s+1,e-1));}
	else{val[s][e] = max(val[s][e],v[s]+dp(s+2,e));}

	x=s;y=e-1;
	if(v[x]<v[y]){val[s][e] = max(val[s][e],v[e]+dp(s,e-2));}
	else{val[s][e] = max(val[s][e],v[e]+dp(s+1,e-1));}

	//cout<<"for "<<s<<","<<e<<" value is---- "<<val[s][e]<<endl;
	return val[s][e];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int c=0;
	while(1){
		c++;
		memset(val,-1,sizeof(val));
		v.clear();
		int n,sum=0,x;
		cin>>n;
		if(n==0){return 0;}

		for(int i=0;i<n;i++){cin>>x;v.push_back(x);sum+=x;}
		int ans = dp(0,n-1);

		cout<<"In game "<<c<<", the greedy strategy might lose by as many as "<<2*ans-sum<<" points."<<endl;
	}
	return 0;
}