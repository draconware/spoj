#include<bits/stdc++.h>
using namespace std;

int n,m,f[100009];
vector<pair<int,int> > b;
int idx[100009];
int cumm[100009];
int val[100009];

int dp(int s){
	if(s>=n){return 0;}
	if(idx[s] == n){return 0;}
	if(val[s] != -1){return val[s];}

	int x = idx[s];
	int sum=0;
	if(s+b[x].second-1 < b[x].first){sum = dp(s+1);}
	else if((s<b[x].first) && (s+b[x].second-1<n)){
		sum = max(dp(s+1),dp(b[x].second+s)+cumm[b[x].second+s-1] - ((s-1)>=0?cumm[s-1]:0));
	}else if((s == b[x].first) && (s+b[x].second-1<n)){
		sum = dp(b[x].second+s)+cumm[b[x].second+s-1] - ((s-1)>=0?cumm[s-1]:0);
	}
	//cout<<s<<" "<<x<<" "<<sum<<endl; 
	val[s]=sum;
	return val[s];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	cin>>n;

	for(int i=0;i<n;i++){cin>>f[i];}
	cin>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		b.push_back(make_pair(x-1,y));
	}
	sort(b.begin(),b.end());
	//for(int i=0;i<m;i++){cout<<b[i].first<<" "<<b[i].second<<endl;}
	for(int i=0;i<=b[0].first;i++){idx[i]=0;}
	for(int i=1;i<m;i++){
		for(int j=b[i-1].first+1;j<=b[i].first;j++){
			idx[j]=i;
		}
	}
	for(int j=b[m-1].first+1;j<n;j++){idx[j]=n;}
	//for(int i=0;i<n;i++){cout<<idx[i]<<" ";}cout<<endl;
	//memset(cumm,0,sizeof(cumm));
	cumm[0]=f[0];
	for(int i=0;i<n;i++){cumm[i] = cumm[i-1]+f[i];}

	memset(val,-1,sizeof(val));
	int ans = dp(0);
	cout<<ans<<endl;
}