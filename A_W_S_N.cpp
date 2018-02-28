#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > choclates;
int n,m;
int cnt=0;
pair<int,int> start,stop;
int dist[109][109];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int inf = 11111111;
int final_dist[20][20];
int dp[2000][20];
char arr[109][109];

bool check(int i,int j){
	if(i<0 || i>=n || j<0 || j>=m){return false;}
	return true;
}

int f(int val,int from){
	if(dp[val][from]!=-1){return dp[val][from];}
	int ans=inf;
	bool flag=false;

	for(int i=0;i<cnt-2;i++){
		if(i!=from && ((1<<i)&val)){
			ans = min(ans,final_dist[from][i]+f((1<<i)^val,i));
			flag=true;
		}
	}
	if(!flag){ans = min(ans,final_dist[from][cnt-1]);}
	//cout<<val<<","<<from<<" "<<ans<<endl;
	dp[val][from] = ans;
	return ans;
}

void bfs(pair<int,int> p){
	bool mark[109][109];
	memset(mark,0,sizeof(mark));
	for(int i=0;i<109;i++){
		for(int j=0;j<109;j++){
			dist[i][j]=inf;
		}
	}

	multiset<pair<int,pair<int,int> > > mul;
	mul.insert(make_pair(0,p));
	dist[p.first][p.second]=0;

	while(!mul.empty()){
		pair<int,pair<int,int> > p = *mul.begin();mul.erase(mul.begin());
		int w = p.first;
		int curr_x=p.second.first,curr_y=p.second.second;

		for(int i=0;i<4;i++){
			int new_x=curr_x+x[i],new_y=curr_y+y[i];

			if(check(new_x,new_y) && arr[new_x][new_y]!='#'){
				if(!mark[new_x][new_y]){
					mark[curr_x][curr_y]=true;
					if(dist[new_x][new_y] > dist[curr_x][curr_y]+1){
						dist[new_x][new_y]=dist[curr_x][curr_y]+1;
						mul.insert(make_pair(dist[new_x][new_y],make_pair(new_x,new_y)));
					}
				}else{
					if(dist[new_x][new_y] > dist[curr_x][curr_y]+1){
						dist[new_x][new_y]=dist[curr_x][curr_y]+1;
						mul.insert(make_pair(dist[new_x][new_y],make_pair(new_x,new_y)));
					}
				}
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		choclates.clear();
		cin>>n>>m;
		
		cnt=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			for(int j=0;j<m;j++){
				if(arr[i][j]=='C'){choclates.push_back(make_pair(i,j));cnt++;}
				else if(arr[i][j]=='T'){cnt++;start = (make_pair(i,j));}
				else if(arr[i][j]=='W'){cnt++;stop = (make_pair(i,j));}
			}
		}
		choclates.push_back(start);choclates.push_back(stop);
		int val = cnt-2;

		for(int i=0;i<cnt;i++){
			bfs(choclates[i]);
			for(int j=0;j<cnt;j++){
				final_dist[i][j] = dist[choclates[j].first][choclates[j].second];
			}
		}

		int ans = inf,value = (1<<val)-1;
		if(val==0){ans = min(ans,final_dist[val][val+1]);}
		else{
			memset(dp,-1,sizeof(dp));
			for(int i=0;i<val;i++){
				ans = min(ans,final_dist[val][i]+f(value^(1<<i),i));
				//cout<<ans<<" ";
			}
		}
		if(ans>=inf){cout<<"Mission Failed!"<<endl;}
		else{
			cout<<ans<<endl;
		}
	}
}