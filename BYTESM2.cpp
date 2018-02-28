#include<bits/stdc++.h>
using namespace std;

int arr[109][109];
int mark[109][109];
int n,m;

int dp(int i,int j){
	if(i>=n || j>=m || j<0){
		return 0;
	}
	if(mark[i][j] != 0){
		return mark[i][j];
	}
	mark[i][j] = arr[i][j]+max(dp(i+1,j-1),max(dp(i+1,j),dp(i+1,j+1)));
	return mark[i][j];
}

int main(){
	
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif

	int t;
	cin>>t;

	while(t--){
		cin>>n>>m;

		memset(mark,0,sizeof(mark));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		int ans=0;
		for(int i=0;i<m;i++){
			ans = max(ans,dp(0,i));
		}
		cout<<ans<<endl;
	}
	return 0;
}