#include<bits/stdc++.h>
using namespace std;

bool mark[50];
int memo[50][50];
int n,k;


int dp(int i,int val){
	if(i>2*n){
		if(val==0){return 1;}
		else{return 0;}
	}
	if(memo[i][val]!=-1){return memo[i][val];}
	if(mark[i]){memo[i][val] = dp(i+1,val+1);}
	else{
		if(i==1){memo[i][val] = dp(i+1,val+1);}
		else if(i==2*n){memo[i][val] = dp(i+1,val-1);}
		else{
			if(val==0){memo[i][val] = dp(i+1,val+1);}
			else{memo[i][val] = (dp(i+1,val+1)+dp(i+1,val-1));}
		}
	}
	return memo[i][val];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		cin>>n>>k;
		memset(mark,0,sizeof(mark));
		memset(memo,-1,sizeof(memo));
		//for(int i=0;i<50;i++){if(mark[i]){cout<<"YES"<<endl;}}
		for(int i=0;i<k;i++){
			int a;
			cin>>a;
			mark[a]=true;
		}
		int ans = dp(1,0);
		cout<<ans<<endl;
	}
}