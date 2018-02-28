#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	LL n,k;
	cin>>n>>k;

	LL arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}

	if(k>=n-1){
		LL ans = 0;
		for(int i=0;i<n;i++){ans = max(ans,arr[i]);}
		cout<<ans<<endl;
	}else{
		bool flag=false;
		LL x=k;
		deque<LL> q;
		for(int i=0;i<n;i++){q.push_back(arr[i]);}
		while(1){
			x = k;
			int y = q.front();
			q.pop_front();
			while(x>0){
				int z = q.front();
				if(y>z){q.pop_front();q.push_back(z);x--;}
				else{q.push_back(y);break;}
			}
			if(x==0){cout<<y<<endl;return 0;}
		}
	}
}