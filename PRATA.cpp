#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int f(int m){
	int res=0;
	for(int i=0;i<v.size();i++){
		res = res + ((-1)+sqrt(1+8*m/v[i]))/2;
		//cout<<res<<" ";
	}
	//cout<<endl;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;

	while(t--){
		v.clear();

		int p,n;
		cin>>p>>n;

		for(int x,i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}	
		sort(v.begin(),v.end());
		//for(int i=0;i<n;i++){cout<<v[i]<<" ";}cout<<endl;

		int l=0,h=10000000,ans=0;
		while(l<=h){
			int m = (l+h)/2;
			//cout<<l<<","<<h<<","<<m<<endl;
			if(f(m) >= p){
				ans=m;
				h=m-1;
			}else{
				l=m+1;
			}
		}
		cout<<ans<<endl;
	}
}