#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v;
int val[1009][209];

int dp(int c,int idx){
	//cout<<c<<endl;
	if(c==0){return 0;}
	if(val[c][idx] != 0){return val[c][idx];}


	for(int i=idx;i<v.size();i++){
		if(v[i].first <= c){
			val[c][idx] = max(val[c][idx],v[i].second + dp(c-v[i].first,i+1));
		}else{
			break;
		}
	}
	return val[c][idx];
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
		int n,k,x,y;
		cin>>k>>n;

		for(int i=0;i<n;i++){
			cin>>x>>y;
			v.push_back(make_pair(x,y));
		}
		sort(v.begin(),v.end());
		memset(val,0,sizeof(val));
		int ans = dp(k,0);
		cout<<"Hey stupid robber, you can get "<<ans<<"."<<endl;
	}
	return 0;
}