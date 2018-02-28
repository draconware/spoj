#include<bits/stdc++.h>
using namespace std;

bool mark[1000001];

int main(){
	memset(mark,1,sizeof(mark));
	for(int i=1;i<1000000;i++){
		int j=i,k=i;
		while(k>0){
			j+=(k%10);
			k/=10;
		}
		mark[j]=false;
	}
	for(int i=1;i<1000000;i++){
		if(mark[i]){cout<<i<<endl;}
	}
}