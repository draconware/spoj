#include<bits/stdc++.h>
using namespace std;

#define M 100000000

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	while(1){
		cin>>n;
		if(n==-1){return 0;}
		vector<pair<int,int> > v;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v.push_back(make_pair(y,x));
		}
		sort(v.begin(),v.end());
		vector<int> s,f;
		for(int i=0;i<n;i++){
			s.push_back(v[i].second);
			f.push_back(v[i].first);
		}

		int val[n];
		memset(val,0,sizeof(val));

		val[0]=1;
		for(int i=1;i<n;i++){
			vector<int>::iterator it = upper_bound(f.begin(),f.end(),s[i]);
			int j = it-f.begin();
			j--;
			if(j>=0){val[i] = (val[j]+1)%M;}
			else{val[i] = (val[i]+1)%M;}
			val[i] = (val[i]+val[i-1])%M;
			//cout<<j<<","<<val[i]<<" ";
		}
		//cout<<endl;
		//for(int i=0;i<n;i++){cout<<val[i]<<" ";}cout<<endl;
		int ans = val[n-1]%M,i=1;
		stack<int> res;
		while(ans>0){
			res.push(ans%10);
			ans/=10;
			i++;
		}
		while(i<=8){
			res.push(0);
			i++;
		}
		while(!res.empty()){
			cout<<res.top();res.pop();
		}
		cout<<endl;
	}
}