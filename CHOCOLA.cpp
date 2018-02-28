#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<LL> x,y;
LL sumx[1009],sumy[1009];
LL val[1009][1009];
int n,m;

LL dp(int i,int j){
	if(i<0){
		return ((LL)(m-i-1))*(sumy[j]);
	}else if(j<0){
		return ((LL)(n-j-1))*(sumx[i]);
	}
	if(val[i][j] != -1){return val[i][j];}

	LL a = n-j-1,b = m-i-1;
	val[i][j] = min(a*x[i]+dp(i-1,j),b*y[j]+dp(i,j-1));
	return val[i][j];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		x.clear();y.clear();
		memset(val,-1,sizeof(val));
		memset(sumx,0,sizeof(sumx));
		memset(sumy,0,sizeof(sumy));

		cin>>m>>n;

		for(int i=0;i<m-1;i++){LL a;cin>>a;x.push_back(a);}
		for(int i=0;i<n-1;i++){LL a;cin>>a;y.push_back(a);}
		
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		
		sumx[0]=x[0];sumy[0]=y[0];
		for(int i=1;i<m-1;i++){
			sumx[i] = sumx[i-1]+x[i];
		}
		for(int i=1;i<n-1;i++){
			sumy[i] = sumy[i-1]+y[i];
		}
		//for(int i=0;i<m-1;i++){cout<<x[i]<<" ";}cout<<endl;
		//for(int i=0;i<n-1;i++){cout<<y[i]<<" ";}cout<<endl;
		//for(int i=0;i<m-1;i++){cout<<sumx[i]<<" ";}cout<<endl;
		//for(int i=0;i<n-1;i++){cout<<sumy[i]<<" ";}cout<<endl;
		LL ans = dp(m-2,n-2);
		cout<<ans<<endl;
	}
	return 0;
}