#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,q,c;
	cin>>n>>q>>c;

	int cnt[15][109][109];
	memset(cnt,0,sizeof(cnt));

	int x,y,z;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		cnt[z][x][y]++;
	}
	for(int i=0;i<=c;i++){
		for(int j=1;j<109;j++){
			for(int k=1;k<109;k++){
				cnt[i][j][k] += cnt[i][j-1][k]+cnt[i][j][k-1]-cnt[i][j-1][k-1];
			}
		}
	}
	int t,x1,y1,x2,y2;
	while(q--){
		cin>>t>>x1>>y1>>x2>>y2;
		int ans=0;
		for(int i=0;i<=c;i++){
			int x = (t+i)%(c+1);
			ans += x*(cnt[x][x2][y2] - cnt[x][x1-1][y2] - cnt[x][x2][y1-1] + cnt[x1-1][y1-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}