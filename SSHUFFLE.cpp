#include<bits/stdc++.h>
using namespace std;

#define LL long long

string a,b,c;
int n1,n2,n3;
LL dp[61][61][61];

LL f(int i,int j,int k){
	if(k==n3){return 1;}
	if(dp[i][j][k]!=-1){return dp[i][j][k];}

	LL sum = 0;
	for(int x=i;x<n1;x++){
		if(a[x]==c[k]){sum += f(x+1,j,k+1);}
	}
	for(int x=j;x<n2;x++){
		if(b[x]==c[k]){sum += f(i,x+1,k+1);}
	}
	dp[i][j][k] = sum;
	return sum;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		cin>>a>>b>>c;
		//cout<<a<<" "<<b<<" "<<c<<endl;
		n1 = a.length();n2 = b.length();n3 = c.length();
		for(int i=0;i<61;i++){
			for(int j=0;j<61;j++){
				for(int k=0;k<61;k++){
					dp[i][j][k]=-1;
				}
			}
		}
		LL ans = f(0,0,0);
		cout<<ans<<endl;
	}
}