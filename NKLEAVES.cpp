#include<bits/stdc++.h>
using namespace std;

#define LL long long

map<pair<int,pair<int,int> > ,LL> m;
map<pair<int,pair<int,int> > ,bool> m1;
LL arr[1000009];
int n,k;

LL f(int i,int j,int x){
	//cout<<i<<" "<<j<<" "<<x<<endl; 
	if(i>n){
		if(j==k){return 0;}
		else{return (LL)1e18;}
	}
	if(j>k){return (LL)1e18;}
	if(m1[make_pair(i,make_pair(j,x))]){return m[make_pair(i,make_pair(j,x))];}

	m[make_pair(i,make_pair(j,x))] = min(f(i+1,j+1,i) , f(i+1,j,x)+(arr[i]*((LL)(i-x))));
	m1[make_pair(i,make_pair(j,x))]=true;
	return m[make_pair(i,make_pair(j,x))];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;

	for(int i=1;i<=n;i++){cin>>arr[i];}

	LL ans = f(2,1,1);
	cout<<ans<<endl;
}

