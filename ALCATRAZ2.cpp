#include<bits/stdc++.h>
using namespace std;

int arr[9];
vector<int> v[9];
bool mark[9][2];
int val[9][2];

int f(int s,int x){
	if(s>8){return 0;}
	if(val[s][x] != -1){return val[s][x];}
	mark[s][x]=true;

	int sum=0;
	if(x==0){
		for(int i=0;i<v[s].size();i++){
			sum = max(arr[s]+f(v[s][i],1),f(v[s][i],0));
		}
	}else{
		for(int i=0;i<v[s].size();i++){
			sum = max(sum,f(v[s][i],0));
		}
	}
	val[s][x]=sum;
	return sum;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n=8;
	for(int i=1,x;i<=8;i++){
		cin>>arr[i];
	}
	int p;
	cin>>p;
	for(int x,y,i=0;i<p;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(mark,0,sizeof(mark));
	memset(val,-1,sizeof(val));
	int ans=0;
	bool check[9];
	for(int i=1;i<=8;i++){
		if(!mark[i][0]){
			//memset(check,0,sizeof(check));
			ans += f(i,0);
			cout<<ans<<endl;
		}
	}
	cout<<ans<<endl;
}