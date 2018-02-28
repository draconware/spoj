#include<bits/stdc++.h>
using namespace std;

vector<int> v;
pair<int,int> val[109][109],P=make_pair(INT_MAX,INT_MAX);

pair<int,int> dp(int i,int n){
	if(n==i){return make_pair(v[i-1],0);}
	if(val[i][n] != P){return val[i][n];}

	for(int j=i;j<n;j++){
		pair<int,int> p1 = dp(i,j);
		pair<int,int> p2 = dp(j+1,n);

		if((p1.first)*(p2.first) + (p1.second) + (p2.second) < val[i][n].second){
			val[i][n] = make_pair(((p1.first)+(p2.first))%100 , (p1.first)*(p2.first) + (p1.second) + (p2.second));
		}
	}
	return val[i][n];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	while(scanf("%d", &n) != EOF){
		v.clear();int x;
		for(int i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		for(int i=0;i<109;i++){
			for(int j=0;j<109;j++){
				val[i][j] = P;
			}
		}
		pair<int,int> p = dp(1,n);
		cout<<p.second<<endl;
	}
	return 0;
}