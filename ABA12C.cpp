#include<bits/stdc++.h>
using namespace std;

int val[109];
vector<int> v;
bool mark[109];
int MAX = 10000000;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int t;
	cin>>t;

	while(t--){
		memset(val,0,sizeof(val));
		memset(mark,0,sizeof(mark));
		v.clear();
		int n,k,x;
		cin>>n>>k;

		for(int i=0;i<k;i++){cin>>x;v.push_back(x);}
		val[0]=0;mark[0]=true;
		for(int i=1;i<=k;i++){
			val[i]=MAX;
			bool flag=false;
			//cout<<"evaluating "<<i<<" --- "<<endl;
			for(int j=0;j<k;j++){
				if(j+1 <= i){
					if(v[j] != -1){
						if(mark[i-j-1]){flag=true;val[i]=min(val[i],val[i-j-1]+v[j]);}
					}
				}else{
					break;
				}
			}
			if(!flag){val[i]=0;}
			if(val[i]>0){mark[i]=true;}
		}
		if(val[k]==0){cout<<"-1"<<endl;}
		else{cout<<val[k]<<endl;}
	}
	return 0;
}