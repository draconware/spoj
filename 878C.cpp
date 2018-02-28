#include<bits/stdc++.h>
using namespace std;

map<int,pair<int,vector<int> > > m;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	vector<pair<char,int> > v;
	for(int i=0;i<n;i++){
		char c;int x;cin>>c>>x;
		v.push_back(make_pair(c,x));
	}
	vector<int> temp;
	temp.push_back(0);
	m[v[0].second] = make_pair(1,temp);
	temp.clear();
	m[0] = make_pair(0,temp);
	int prev=v[0].second,curr;
	for(int i=1;i<n;i++){
		if(v[i].first == '|'){
			curr = (prev)|(v[i].second);
			if(curr!=0 && m[curr].first!=0){
				if(m[curr].first > m[prev].first+1){
					m[curr].first = m[prev].first+1;
					vector<int> x = m[prev].second;
					x.push_back(i);
					m[curr].second = x;
				}
			}else if(curr!=0){
				m[curr].first = m[prev].first+1;
				vector<int> x = m[prev].second;
				x.push_back(i);
				m[curr].second = x;
			}
		}
		if(v[i].first == '&'){
			curr = (prev)&(v[i].second);
			if(curr!=0 && (m[curr].first)!=0){
				if(m[curr].first > m[prev].first+1){
					m[curr].first = m[prev].first+1;
					vector<int> x;
					x = m[prev].second;
					x.push_back(i);
					m[curr].second = x;
				}
			}else if(curr!=0){
				m[curr].first = m[prev].first+1;
				vector<int> x;
				x = m[prev].second;
				x.push_back(i);
				m[curr].second = x;
			}
		}
		if(v[i].first == '^'){
			curr = (prev)^(v[i].second);
			if(curr!=0 && (m[curr].first)!=0){
				if(m[curr].first > m[prev].first+1){
					m[curr].first = m[prev].first+1;
					vector<int> x;
					x = m[prev].second;
					x.push_back(i);
					m[curr].second = x;
				}
			}else if(curr!=0){
				m[curr].first = m[prev].first+1;
				vector<int> x;
				x = m[prev].second;
				x.push_back(i);
				m[curr].second = x;
			}
		}
		prev = curr;
	}
	int ans = m[prev].first;
	cout<<ans<<endl;
	if(ans>0){
		vector<int> x = m[prev].second;
		for(int i=0;i<x.size();i++){
			cout<<v[x[i]].first<<" "<<v[x[i]].second<<endl;
		}
	}
	return 0;
}