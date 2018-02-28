#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int x,y,a,b;
	cin>>a>>b;

	vector<pair<pair<int,int> ,int> > v;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		v.push_back(make_pair(make_pair(x,y),i+1));
	}
	sort(v.begin(),v.end());
	int j=n;
	for(int i=0;i<n;i++){
		if(v[i].first.first >= a && v[i].first.second >= b){
			j=i;break;
		}
	}
	cout<<n-j<<endl;
	if(j!=n){
		for(int i=j;i<n;i++){
			cout<<v[i].second<<" ";
		}cout<<endl;
	}
}