#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
 	freopen("output.out","w",stdout);
  	#endif
	int t,c=0;
	cin>>t;

	while(t--){
		c++;
		int n;
		cin>>n;

		long long x,ans=1,res=1;
		for(int i=0;i<n;i++){
			cin>>x;
			ans*=x;
		}
		ans++;

		for(long long i=2;i<=ans;i++){
			if(ans%i == 0){res = max(res,i);}
			while(ans%i == 0){
				ans/=i;
			}
		}
		if(ans != 1){res = max(res,ans);}
		cout<<"Case #"<<c<<": "<<res<<endl;
	}
	return 0;
}