#include<bits/stdc++.h>
using namespace std;

map<string,int> mark;
string abb;
vector<string> v;
int dp[109][150][150][2];

int f(int i,int j,int k,int p){
	if(i==abb.size()){
		if(j < v.size()-1){return 0;}
		else if(j == v.size()-1){return p;}
		else{return 1;}
	}
	if(j==v.size()){
		if(i>=abb.size()){return 1;}
		else{return 0;}
	}
	if(dp[i][j][k][p] != -1){return dp[i][j][k][p];}
	int sum;
	if(k>=v[j].size()){if(p==1){return f(i,j+1,0,0);}else{return 0;}}
	else{
		char x = tolower(abb[i]),y = tolower(v[j][k]);
		//cout<<x<<" "<<y<<endl;
		sum =0;
		if(x==y){sum = f(i+1,j+1,0,0)+f(i+1,j,k+1,1);}
		if(p==1){sum += f(i,j+1,0,0);}
		sum+=f(i,j,k+1,p);
		dp[i][j][k][p]=sum;
	}
	return dp[i][j][k][p];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(1){
		int n;
		cin>>n;
		if(n==0){return 0;}
		//memset(mark,0,sizeof(mark));
		mark.clear();
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			mark[s]=true;
		}
		while(1){
			v.clear();
			cin>>abb;
			if(abb == "LAST"){break;}
			getline(cin,s);
			//cout<<s<<endl;
			int x = s.length();
			string temp;
			for(int i=1;i<x;i++){
				if(s[i]==' '){
					if(!mark[temp]){v.push_back(temp);}
					temp.clear();
				}else{
					temp.push_back(s[i]);
				}
			}
			v.push_back(temp);
			memset(dp,-1,sizeof(dp));
			if(v.size() > abb.size()){cout<<abb<<" is not a valid abbreviation"<<endl;}
			else{
				int ans = f(0,0,0,0);
				//cout<<abb<<endl;
				//for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl;
				if(ans == 0){cout<<abb<<" is not a valid abbreviation"<<endl;}
				else{cout<<abb<<" can be formed in "<<ans<<" ways"<<endl;}
			}
		}
	}
}