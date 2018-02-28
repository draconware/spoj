#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL f(LL arr[],LL n){
	LL rarr[n];
	for(int i=0;i<n;i++){
		rarr[i] = arr[n-1-i];
	}
	LL x=0;
	stack<LL> s;
	LL val[n];
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
		val[y] = arr[y] *(n-y);
		s.pop();
	}
	//for(int i=1;i<=n;i++){cout<<val[i]<<" ";}cout<<endl;
	x=0;
	s.push(x);x++;
	while(x<=n){
		if(rarr[x] >= rarr[s.top()]){s.push(x);}
		else{
			while(!s.empty() && (rarr[s.top()] > rarr[x])){
				LL y = s.top();
				val[n-1-y] += (rarr[y]*(x-y));
				s.pop();
			}
			s.push(x);
		}
		x++;
	}
	while(!s.empty()){
		LL y = s.top();
		val[n-1-y] += (rarr[y] *(n-y));
		s.pop();
	}
	//for(int i=1;i<=n;i++){cout<<val[i]<<" ";}cout<<endl;
	for(LL i=0;i<n;i++){val[i]-=arr[i];}
	LL ans = 0;
	for(LL i=1;i<=n;i++){ans = max(ans,val[i]);}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		LL n,m;
		cin>>n>>m;

		char arr[n][m];
		for(LL i=0;i<n;i++){
			for(LL j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		LL ans=0;
		LL val[n+1][m+1];
		memset(val,0,sizeof(val));
		for(LL j=m-1;j>=0;j--){
			for(LL i=0;i<n;i++){
				if(arr[i][j] == 'R'){val[i][j] = 0;}
				else{val[i][j] = val[i][j+1]+1;}
			}
		}
		for(LL j=0;j<m;j++){
			LL x[n];
			for(LL i=0;i<n;i++){
				x[i] = val[i][j];
			}
			ans = max(ans,f(x,n));
		}
		memset(val,0,sizeof(val));
		for(LL i=0;i<n;i++){
			if(i==0){for(LL j=0;j<m;j++){if(arr[i][j]=='R'){val[i][j]=0;}else{val[i][j]=1;}}continue;}
			for(LL j=0;j<m;j++){
				if(arr[i][j]=='R'){val[i][j] = 0;}
				else{val[i][j] = val[i-1][j]+1;}
			}
		}
		for(LL i=0;i<n;i++){
			LL x[m];
			for(LL j=0;j<m;j++){
				x[j]=val[i][j];
			}
			ans = max(ans,f(x,m));
		}
		cout<<3*ans<<endl;
	}
}