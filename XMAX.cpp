#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	vector<LL> v(n);
	for(int i=0;i<n;i++){cin>>v[i];}

	sort(v.rbegin(),v.rend());
	
	LL x=1;
	while(v[0]>=x){x<<=1;}
	x>>=1;
	for(int i=0;x>=1;x>>=1){
		int j=i;
		//cout<<x<<endl;
		while(j<n && (v[j]&x)==0){j++;}
		if(j>=n){continue;}

		swap(v[j],v[i]);
		for(j=0;j<n;j++){
			if(j!=i && (v[j]&x)!=0){v[j] = v[j]^v[i];}
		}
		//for(int j=0;j<n;j++){cout<<v[j]<<" ";}cout<<endl;
		i++;
	}
	LL ans=0;
	for(int i=0;i<n;i++){ans = ans^v[i];}
	cout<<ans<<endl;
}