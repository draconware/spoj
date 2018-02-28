#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<pair<long double,long double>,pair<long double,long double> > > v;
long double low,high;
long double V;

void f(){
	while(high-low > 1e-8){
		long double m = (low+high)/2.0;
		long double volume=0;
		for(int i=0;i<n;i++){
			if(m>v[i].first.first){
				if(m>=(v[i].first.first + v[i].first.second)){
					volume += ((v[i].first.second) * (v[i].second.first) * (v[i].second.second));
				}else{
					volume += ((m - v[i].first.first) * (v[i].second.first) * (v[i].second.second));
				}
			}
		}
		if(volume<V){low=m;}
		else{high=m;}
	}
	printf("%.2f\n",low);
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
		cin>>n;

		low = 100000000,high = -100000000;
		long double TV=0;
		for(int i=0;i<n;i++){
			long double a,b,c,d;
			cin>>a>>b>>c>>d;

			v.push_back(make_pair(make_pair(a,b),make_pair(c,d)));
			if(low>(a+b)){low=a+b;}
			if(high<(a+b)){high=a+b;}
			TV += (b*c*d);
		}
		cin>>V;
		//cout<<TV<<" "<<V<<endl;
		if(TV < V){cout<<"OVERFLOW"<<endl;}
		else{
			f();
		}
	}
}