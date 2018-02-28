#include<bits/stdc++.h>
using namespace std;

set<int> s;
vector<int> v;
bool mark[10000];
int arr[4],k;
int val[4][10000];

void pre(){
	memset(mark,1,sizeof(mark));
	mark[1]=false;
	for(int i=2;i<10000;i++){
		if(mark[i]){
			for(int j=i*i;j<10000;j+=i){
				mark[j]=false;
			}
		}
	}
	for(int i=1;i<100;i++){
		for(int j=i;j<100;j++){
			if(mark[i*i + j*j]){
				s.insert(i*i + j*j);
			}
		}
	}
	for(set<int>::iterator it = s.begin();it!=s.end();it++){
		//cout<< *it <<" ";
		v.push_back(*it);
	}
}

int dp(int i,int n){
	if(n==0){return 1;}
	if(n<=0){return 0;}
	if(i>=k){return 0;}
	if(val[i][n] != -1){return val[i][n];}

	val[i][n] = dp(i,n-arr[i])+dp(i+1,n);
	return val[i][n];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	pre();
	
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n>>k;

		for(int i=0;i<k;i++){arr[i]=i+1;}
		memset(val,-1,sizeof(val));
		//cout<<v[n-1]<<endl;
		cout<<dp(0,v[n-1])<<endl;
	}
	return 0;
}