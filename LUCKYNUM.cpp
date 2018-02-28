#include<bits/stdc++.h>
using namespace std;

bool mark[209][10009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		memset(mark,0,sizeof(mark));
		queue<pair<pair<int,int>,pair<int,int> > > q;
		q.push(make_pair(make_pair(1,6%n),make_pair(0,0)));
		q.push(make_pair(make_pair(1,8%n),make_pair(1,1)));
		mark[1][8%n]=true;
		mark[1][6%n]=true;

		int ans=-1,length=-1;
		while(!q.empty()){
			int len = q.front().first.first;
			int u = q.front().first.second;
			int flag = q.front().second.second;
			int eight = q.front().second.first;
			q.pop();

			if(u==0){
				ans = eight;length = len;break;
			}
			if(len>=200){continue;}
			if(flag){
				int v = ((u*(10%n))%n + (8%n))%n;
				if(!mark[len+1][v]){
					q.push(make_pair(make_pair(len+1,v),make_pair(eight+1,1)));
				}
				v = ((u*(10%n))%n + (6%n))%n;
				if(!mark[len+1][v]){
					q.push(make_pair(make_pair(len+1,v),make_pair(eight,0)));
				}
			}else{
				int v = ((u*(10%n))%n + (6%n))%n;
				if(!mark[len+1][v]){
					q.push(make_pair(make_pair(len+1,v),make_pair(eight,0)));
				}
			}
		}
		if(ans==-1 || length==-1){cout<<"-1";}
		for(int i=1;i<=ans;i++){cout<<"8";}
		for(int i=ans+1;i<=length;i++){cout<<"6";}cout<<endl;
	}
}