#include<bits/stdc++.h>
using namespace std;

struct block{
	int h,w,d;
};

bool comp(block x,block y){
	if((x.d * x.w) > (y.d * y.w)){return true;}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(1){
		int n;
		cin>>n;
		if(n==0){return 0;}

		struct block arr[3*n+1];
		for(int i=0;i<n;i++){
			int a,b,c;cin>>a>>b>>c;
			arr[3*i].h = a;arr[3*i].w = b;arr[3*i].d = c;
			arr[3*i+1].h = b;arr[3*i+1].w = max(a,c);arr[3*i+1].d = min(a,c);
			arr[3*i+2].h = c;arr[3*i+2].w = max(a,b);arr[3*i+2].d = min(a,b);
		}
		sort(arr,arr+3*n,comp);
		//for(int i=0;i<3*n;i++){cout<<(arr[i].d * arr[i].w)<<" ";}cout<<endl;
		int dp[3*n];
		for(int i=0;i<3*n;i++){dp[i]=arr[i].h;}

		for(int i=1;i<3*n;i++){
			for(int j=0;j<i;j++){
				if(((arr[i].d < arr[j].d) && (arr[i].w < arr[j].w))||(((arr[i].d < arr[j].w) && (arr[i].w < arr[j].d)))){dp[i] = max(dp[i],dp[j]+arr[i].h);}
			}
		}
		int ans=0;
		for(int i=0;i<3*n;i++){ans = max(ans,dp[i]);}
		cout<<ans<<endl;
	}
}