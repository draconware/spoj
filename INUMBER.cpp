#include<bits/stdc++.h>
using namespace std;

#define MAX 1000;

pair<int,int> parent[1001][1001];
int val[1001][1001];

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

		memset(val,-1,sizeof(val));
		memset(parent,0,sizeof(parent));

		queue<pair<int,int> > q;
		for(int i=1;i<=9;i++){
			val[i%n][i] = i;
			q.push(make_pair(i%n,i));
		}

		while(!q.empty()){
			pair<int,int> p = q.front();q.pop();

			int mod = p.first;
			int sum = p.second;
			//cout<<mod<<" "<<sum<<" makes ------ ";
			if(mod==0 && sum==n){break;}

			for(int i=0;i<=9;i++){
				int j = (mod*10 + i)%n;
				int k = sum+i;

				if(k>n || (val[j][k] != -1)){continue;}
				//cout<<j<<","<<k<<" ";
				val[j][k] = i;
				parent[j][k] = make_pair(mod,sum);
				q.push(make_pair(j,k));
			}
			//cout<<endl;
		}
		stack<int> s;
		int mod=0,sum=n;
		while(sum>0){
			s.push(val[mod][sum]);
			int temp = mod;
			mod = parent[mod][sum].first;
			sum = parent[temp][sum].second;
		}
		while(!s.empty()){cout<<s.top();s.pop();}cout<<endl;
	}
	return 0;
}