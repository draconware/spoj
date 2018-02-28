#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL M = 1e9+7;

LL power(LL y){
	LL res=1,x=3;
	while(y>0){
		if(y%2 == 1){res = (res*x)%M;}
		y/=2;
		x = (x*x)%M;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;

	while(t--){
		LL n;
		cin>>n;

		if(n==0){cout<<"1"<<endl;}
		else if(n<=3){cout<<n<<endl;}
		else{
			LL n1;
			if(n%3==1){n1 = (n-4)/3;}
			else if(n%3==2){n1 = (n-2)/3;}
			else{n1 = n/3;}

			LL ans = power(n1);
			if(n%3 == 1){ans = (ans*4)%M;}
			else if(n%3 == 2){ans = (ans*2)%M;}
			cout<<ans<<endl;
		}
	}
	return 0;
}