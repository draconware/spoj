#include<bits/stdc++.h>
using namespace std;

char s[109],t[109];
int dp[109][109];

void lcs(int n1,int n2){
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(s[i-1] == t[j-1]){dp[i][j] = dp[i-1][j-1]+1;}
			else{dp[i][j] = max(dp[i-1][j],dp[i][j-1]);}
		}
	}
	//return dp[n1][n2];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(scanf("%s %s", s, t) != EOF){
		int n1 = strlen(s);
		int n2 = strlen(t);

		lcs(n1,n2);
		int i=n1,j=n2;
		stack<char> st;
		while(i>0 && j>0){
			if(s[i-1] == t[j-1]){st.push(s[i-1]);i--;j--;}
			else{
				if(dp[i-1][j] > dp[i][j-1]){st.push(s[i-1]);i--;}
				else{st.push(t[j-1]);j--;}
			}
		}
		while(i>0){
			st.push(s[i-1]);
			i--;
		}
		while(j>0){
			st.push(t[j-1]);
			j--;
		}
		while(!st.empty()){
			cout<<st.top();
			st.pop();
		}
		cout<<endl;
	}
}