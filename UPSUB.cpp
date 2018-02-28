#include<bits/stdc++.h>
using namespace std;

vector<pair<string,int> > v;
int dp[109];

void backtrack(string s,int m){
	int n = (int)s.length();
	string str;
	for(int i=0;i<n;i++){
		string str(1,s[i]);
		if(dp[i]==1){v.push_back(make_pair(str,i));}
	}
	for(int len=2;len<=m;len++){
		vector<pair<string,int> > temp;
		for(int i=0;i<v.size();i++){
			string x = v[i].first;int idx = v[i].second;
			for(int j=idx+1;j<n;j++){
				if(dp[j]==len && s[j]>=x[len-2]){
					temp.push_back(make_pair(x+s[j],j));
				}
			}
		}
		v.clear();
		for(int i=0;i<temp.size();i++){v.push_back(temp[i]);}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){cout<<v[i].first<<endl;}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;
		//cout<<s<<endl;

		int n = (int)s.length();
		//cout<<n<<endl;
		for(int i=0;i<n;i++){dp[i]=1;}
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(s[i] >= s[j]){dp[i] = max(dp[i],dp[j]+1);}
			}
			//cout<<dp[i]<<" ";
		}
		cout<<endl;
		int x=0;
		for(int i=0;i<n;i++){x = max(x,dp[i]);}
		//cout<<x<<endl;
		v.clear();
		backtrack(s,x);
	}
	return 0;
}