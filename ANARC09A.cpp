#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int c=0;
	while(1){
		c++;
		string s;
		cin>>s;
		if(s[0]=='-'){break;}

		int x=0,y=0;
		int n = (int)s.length();
		for(int i=0;i<n;i++){
			if(s[i]=='{'){x++;}
			else{
				x--;
				if(x<0){x=1;y++;}
			}
		}
		cout<<c<<". "<<y+(x/2)<<endl;
	}
	return 0;
}