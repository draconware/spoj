#include<bits/stdc++.h>
using namespace std;

int lps[1000009];
vector<int> res;

void preprocess(string patt){
	int m = (int)patt.length();
	lps[0]=0;
	int i=1,len=0;

	while(i<m){
		if(patt[i]==patt[len]){
			len++;
			lps[i]=len;
			i++;
		}else{
			if(len>0){len = lps[len-1];}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		res.clear();
		string text,patt;
		cin>>text>>patt;

		int n = (int)text.length();
		int m = (int)patt.length();
		preprocess(patt);

		int i=0,j=0;
		while(i<n){
			if(text[i] == patt[j]){
				i++;j++;
				if(j==m){res.push_back(i-j+1);j=lps[j-1];}
			}else{
				if(j>0){j = lps[j-1];}
				else{
					i++;
				}
			}
		}
		n = (int)res.size();
		if(n==0){cout<<"Not Found"<<endl;}
		else{
			cout<<n<<endl;
			for(int i=0;i<n;i++){cout<<res[i]<<" ";}cout<<endl;
		}
	}
}