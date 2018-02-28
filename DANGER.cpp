#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string s;
	while(1){
		cin>>s;
		if(s=="00e0"){break;}
		int n=0;
		n = n*10+(s[0]-'0');
		n = n*10+(s[1]-'0');
		int x = (int)pow(10,s[3]-'0');
		n*=x;
		//cout<<n<<" ";

		int y = (int)floor(log2(n));
		y = (int)pow(2,y);
		cout<<2*(n-y)+1<<endl;
	}
	return 0;
}