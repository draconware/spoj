#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	int arr[n+1][n+1];
	memset(arr,0,sizeof(arr));

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		arr[x][y]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j] = arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+arr[i][j];
		}
	}
	int ans = INT_MIN;
	for(int i=1;i*i<=m;i++){
		if(m%i == 0){
			int x1 = i;
			int x2 = m/i;
			for(int j=1;j+x1-1<=n;j++){
				for(int k=1;k+x2-1<=n;k++){
					int x = arr[j+x1-1][k+x2-1]-arr[j+x1-1][k-1]-arr[j-1][k+x2-1]+arr[j-1][k-1];
					ans = max(ans,x);
				}
			}
			for(int j=1;j+x2-1<=n;j++){
				for(int k=1;k+x1-1<=n;k++){
					int y = arr[j+x2-1][k+x1-1]-arr[j+x2-1][k-1]-arr[j-1][k+x1-1]+arr[j-1][k-1];
					ans = max(ans,y);
				}
			}
		}
	}
	cout<<m-ans<<endl;
}