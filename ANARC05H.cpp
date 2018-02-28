#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dp(int i,int last){
	//cout<<i<<","<<last<<endl;
	if(i == n){
		return 1;
	}
	int res=0,temp=0,sum=0;
	for(int j=i;j<n;j++){
		sum += (s[j]-'0');
		if(sum>=last){
			res = res + dp(j+1,sum);
		}
	}

	return res;
}

int main(){
	int k=0;
	while(1){
		k++;
		cin>>s;
		n=s.length();
		if(s == "bye"){return 0;}
		int ans=0;
		ans = dp(0,0);
		cout<<k<<". "<<ans<<endl;
	}
	return 0;
}