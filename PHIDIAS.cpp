#include<bits/stdc++.h>
using namespace std;

int n;
//vector<pair<int,int> > v;
int val[609][609];

int dp(int w,int h){
	if(val[w][h] != -1){return val[w][h];}
	int res = val[w][h] = w*h;
	for(int i=1;i <=( w>>1);i++){
		int temp = dp(i,h);
		if(temp<res){temp+=dp(w-i,h);}
		if(temp<res){res=temp;}
	}
	for(int i=1;i <= (h>>1);i++){
		int temp = dp(w,i);
		if(temp<res){temp+=dp(w,h-i);}
		if(temp<res){res=temp;}
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		int w,h;
		cin>>w>>h>>n;
		memset(val,-1,sizeof(val));
		//for(int i=0;i<609;i++){val[i][0]=0;val[0][i]=0;}
		//val[1][1]=1;
		for(int i=0;i<n;i++){
			int x,y;cin>>x>>y;
			//v.push_back(make_pair(x,y));
			val[x][y]=0;
		}
		cout<<dp(w,h)<<endl;
	}
}