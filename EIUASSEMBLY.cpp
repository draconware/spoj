#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long

vector<pair<LL,LL> > v;
LL m;
int n;

bool f(LL c){
	LL m1=m;
	for(int i=0;i<n;i++){
		if(v[i].first < c){
			if((c-v[i].first)*(v[i].second) <= m1){
				m1-=((c-v[i].first)*(v[i].second));
			}else{
				return false;
			}
		}
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		v.clear();
		cin>>n>>m;
		for(int i=0;i<n;i++){
			LL x,y;
			cin>>x>>y;
			v.push_back(make_pair(x,y));
		}
		LL l=1,h=10000000000000,x=1;
		while(l<=h){
			LL mid = l+(h-l)/2;
			if(f(mid)){
				x=mid;
				l=mid+1;
			}else{
				h=mid-1;
			}
		}
		cout<<x<<endl;
	}
}