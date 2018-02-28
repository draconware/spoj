#include<bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif
	
	int t;
	cin>>t;

	while(t--){
		string s,rs;
		cin>>s;

		int m,n;
		m=s.length();n=s.length();
		for(int i=s.length()-1;i>=0;i--){
			rs.push_back(s[i]);
		}
		int mark[m+9][n+9];
		for (int i=0; i<=m; i++){
    	 	for (int j=0; j<=n; j++){
      			 if (i == 0 || j == 0)
         			mark[i][j] = 0;
  
       			else if (s[i-1] == rs[j-1])
         			mark[i][j] = mark[i-1][j-1] + 1;
  
       			else
         			mark[i][j] = max(mark[i-1][j], mark[i][j-1]);
     		}
  		 }
		cout<<m-mark[m][n]<<endl;
	}
	return 0;
}