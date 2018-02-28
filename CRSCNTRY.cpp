#include<bits/stdc++.h>
using namespace std;

vector<int> agens,tom;

int lcs(){
	int n = (int)agens.size(),m = (int)tom.size();
	//cout<<"evaluating---- "<<endl;
	//for(int i=0;i<n;i++){cout<<agens[i]<<" ";}cout<<endl;
	//for(int i=0;i<m;i++){cout<<tom[i]<<" ";}cout<<endl;
	int dp[n+1][m+1];	
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(agens[i-1] == tom[j-1]){dp[i][j] = dp[i-1][j-1]+1;}
			else{dp[i][j] = max(dp[i-1][j],dp[i][j-1]);}
		}
	}
	return dp[n][m];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		agens.clear();tom.clear();

		int x;
		while(1){
			cin>>x;
			if(x==0){break;}
			agens.push_back(x);
		}
		int ans=0;
		while(1){
			cin>>x;
			if(x==0){break;}
			tom.clear();
			tom.push_back(x);
			while(1){
				cin>>x;
				if(x==0){break;}
				tom.push_back(x);
			}
			ans = max(ans,lcs());
		}
		cout<<ans<<endl;
	}
	return 0;
}