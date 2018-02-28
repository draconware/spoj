#include<bits/stdc++.h>
using namespace std;

int dp[2][4][4][4][4];

int value(int a,int b,int c){
	int sol=0;
	if (a == 1 || b == 1 || c == 1) sol++;
  	if (a == 2 || b == 2 || c == 2) sol++;
  	if (a == 3 || b == 3 || c == 3) sol++;
  	return sol;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	string s;
	cin>>s;
	int arr[n];
	for(int i=0;i<n;i++){
		if(s[i]=='M'){arr[i]=1;}
		else if(s[i]=='F'){arr[i]=2;}
		else{arr[i]=3;}
	}

	for(int i=n-1;i>=0;i--){
		for(int a=0;a<=3;a++){
			for(int b=0;b<=3;b++){
				for(int c=0;c<=3;c++){
					for(int d=0;d<=3;d++){
						dp[i%2][a][b][c][d] = max(dp[(i+1)%2][b][arr[i]][c][d]+value(a,b,arr[i]),dp[(i+1)%2][a][b][d][arr[i]]+value(c,d,arr[i]));
					}
				}
			}
		}
	}
	cout<<dp[0][0][0][0][0]<<endl;	
}