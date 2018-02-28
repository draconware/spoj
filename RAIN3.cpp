#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int c;
	cin>>c;

	while(c--){
		LL s,t,n,k;
		cin>>s>>t>>n>>k;

		LL arr[n];
		for(int i=0;i<n;i++){
			s = (78901 + 31*s)%699037;
			t = (23456 + 64*t)%2097151;
			arr[i] = (s%100 + 1)*(t%100 + 1);
		}
		//for(int i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

		LL sum=0;
		int x=0;
		deque<LL> q;
		while(x<n){
			if(sum+arr[x]<=k){q.push_back(arr[x]);sum+=arr[x];}
			else{break;}
			x++;
		}
		int ans = x,temp;
		//cout<<ans<<" "<<sum<<endl;
		for(int i=x;i<n;i++){
			while(!q.empty() && sum+arr[i]>k){sum-=q.front();q.pop_front();}
			if(sum+arr[i]<=k){q.push_back(arr[i]);sum+=arr[i];}
			ans = min(ans,(int)q.size());
		}
		cout<<ans<<endl;
	}
	return 0;
}