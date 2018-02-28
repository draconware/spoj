#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(1){
		//cout<<"executed"<<endl;
		LL n;
		cin>>n;

		if(n==0){return 0;}
		LL arr[n+1],rarr[n+1];
		for(LL i=1;i<=n;i++){cin>>arr[i];}
		for(LL i=1;i<=n;i++){rarr[i] = arr[n-i+1];}

		LL x=1;
		stack<LL> s;
		LL val[n+1];
		memset(val,0,sizeof(val));
		s.push(x);x++;
		while(x<=n){
			if(arr[x] >= arr[s.top()]){s.push(x);}
			else{
				while(!s.empty() && (arr[s.top()] > arr[x])){
					LL y = s.top();
					val[y] = arr[y] * (x-y);
					s.pop();
				}
				s.push(x);
			}
			x++;
		}
		while(!s.empty()){
			LL y = s.top();
			val[y] = arr[y] *(n+1-y);
			s.pop();
		}
		//for(int i=1;i<=n;i++){cout<<val[i]<<" ";}cout<<endl;
		x=1;
		s.push(x);x++;
		while(x<=n){
			if(rarr[x] >= rarr[s.top()]){s.push(x);}
			else{
				while(!s.empty() && (rarr[s.top()] > rarr[x])){
					LL y = s.top();
					val[n+1-y] += (rarr[y]*(x-y));
					s.pop();
				}
				s.push(x);
			}
			x++;
		}
		while(!s.empty()){
			LL y = s.top();
			val[n+1-y] += (rarr[y] *(n+1-y));
			s.pop();
		}
		//for(int i=1;i<=n;i++){cout<<val[i]<<" ";}cout<<endl;
		for(LL i=1;i<=n;i++){val[i]-=arr[i];}
		LL ans = 0;
		for(LL i=1;i<=n;i++){ans = max(ans,val[i]);}
		cout<<ans<<endl;
	}
	return 0;
}