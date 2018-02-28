#include<bits/stdc++.h>
using namespace std;

int val[10050];
int p[600],w[600];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		int e,f,n;
		cin>>e>>f>>n;
		f-=e;
		val[0]=0;

		for(int i=0;i<n;i++){
			cin>>p[i]>>w[i];
		}
		for(int i=1;i<=f;i++){
			val[i]=-1;
			for(int j=0;j<n;j++){
				if(i>=w[j] && val[i-w[j]]!=-1 && (val[i] == -1 || p[j]+val[i-w[j]] <= val[i])){
					val[i] = p[j]+val[i-w[j]];
				}
			}
		}
		if(val[f] == -1){cout<<"This is impossible."<<endl;}
		else{cout<<"The minimum amount of money in the piggy-bank is "<<val[f]<<"."<<endl;}
	}
}