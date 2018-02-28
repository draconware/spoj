#include<bits/stdc++.h>
using namespace std;

vector<int> v[20];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t,c=0;
	cin>>t;

	v[1].push_back(2);v[1].push_back(3);v[1].push_back(9);v[1].push_back(5);
	v[2].push_back(1);v[2].push_back(10);v[2].push_back(4);v[2].push_back(6);
	v[3].push_back(1);v[3].push_back(4);v[3].push_back(11);v[3].push_back(7);
	v[4].push_back(2);v[4].push_back(3);v[4].push_back(8);v[4].push_back(12);
	v[5].push_back(1);v[5].push_back(6);v[5].push_back(7);v[5].push_back(13);
	v[6].push_back(2);v[6].push_back(5);v[6].push_back(8);v[6].push_back(14);
	v[7].push_back(3);v[7].push_back(5);v[7].push_back(8);v[7].push_back(15);
	v[8].push_back(4);v[8].push_back(6);v[8].push_back(7);v[8].push_back(16);
	v[9].push_back(1);v[9].push_back(10);v[9].push_back(11);v[9].push_back(13);
	v[10].push_back(2);v[10].push_back(9);v[10].push_back(12);v[10].push_back(14);
	v[11].push_back(3);v[11].push_back(9);v[11].push_back(12);v[11].push_back(15);
	v[12].push_back(4);v[12].push_back(10);v[12].push_back(11);v[12].push_back(16);
	v[13].push_back(5);v[13].push_back(9);v[13].push_back(14);v[13].push_back(15);
	v[14].push_back(6);v[14].push_back(10);v[14].push_back(13);v[14].push_back(16);
	v[15].push_back(7);v[15].push_back(11);v[15].push_back(13);v[15].push_back(16);
	v[16].push_back(8);v[16].push_back(12);v[16].push_back(14);v[16].push_back(15);
	while(t--){
		c++;
		vector<int> arr;
		for(int i=1,x;i<=16;i++){cin>>x;arr.push_back(x);}

		queue<pair<int,vector<int> > > q;
		q.push(make_pair(0,arr));

		bool flag=false;
		bool mark[20];
		memset(mark,0,sizeof(mark));
		int ans;
		while(!q.empty()){
			pair<int,vector<int> > p = q.front();q.pop();
			int w = p.first;
			vector<int> temp = p.second;
			vector<int> temp2;
			if(w>3){break;}
			bool chk=true;
			for(int i=0;i<8;i++){if(temp[i]!=0){chk=false;}}
			if(chk){
				for(int i=8;i<16;i++){if(temp[i]!=0){chk=false;}}
			}
			if(chk){flag=true;ans = w;break;}

			for(int i=0;i<8;i++){
				if(temp[i] == 1){
					mark[i+1]=true;
					for(int j=0;j<v[i+1].size();j++){
						if(!mark[v[i+1][j]] && temp2[v[i+1][j]-1]==0){
							temp2[i]=0;temp2[v[i+1][j]-1]=1;
							q.push(make_pair(w+1,temp2));
							temp2.clear();
							for(int i=0;i<16;i++){temp2.push_back(temp[i]);}
						}
					}
				}
			}
		}
		if(flag){cout<<"Case #"<<c<<": "<<ans<<endl;}
		else{cout<<"Case #"<<c<<": more"<<endl;}

	}
}