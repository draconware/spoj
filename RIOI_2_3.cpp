#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,sx,sy,ex,ey;
		cin>>n;

		int x,arr[n][n];
		int level[n][n];
		bool mark[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
				level[i][j]=INT_MAX;
				mark[i][j]=false;
			}
		}
		cin>>sx>>sy>>ex>>ey;
		set<int> s;
		s.insert(arr[sx][sy]);
		s.insert(arr[ex][ey]);
		if(arr[sx][sy] == arr[ex][ey]){x=1;}
		else{x=2;}
		multiset<pair<pair<int,int>,pair<int,set<int> > > > m;
		m.insert(make_pair(make_pair(x,sx),make_pair(sy,s)));
		level[sx][sy]=x;

		while(!m.empty()){
			pair<pair<int,int>,pair<int,set<int> > > p = *m.begin();m.erase(m.begin());
			int w=p.first.first,x=p.first.second,y=p.second.first;
			s = p.second.second;
			if(mark[x][y]){continue;}
			//cout<<x<<","<<y<<" "<<w<<endl;
			mark[x][y]=true;
			if(x==ex && y==ey){cout<<w<<endl;break;}

			set<int> temp;
			temp.insert(s.begin(),s.end());
			if(x-1>=0 && !mark[x-1][y]){
				if(temp.find(arr[x-1][y]) != temp.end()){
					if(level[x][y] < level[x-1][y]){
						level[x-1][y]=level[x][y];
						m.insert(make_pair(make_pair(level[x-1][y],x-1),make_pair(y,temp)));
					}
				}else{
					if(level[x][y]+1 < level[x-1][y]){
						temp.insert(arr[x-1][y]);
						level[x-1][y] = level[x][y]+1;
						m.insert(make_pair(make_pair(level[x-1][y],x-1),make_pair(y,temp)));
						temp.erase(arr[x-1][y]);
					}
				}
			}
			if(x+1<n && !mark[x+1][y]){
				if(temp.find(arr[x+1][y]) != temp.end()){
					if(level[x][y] < level[x+1][y]){
						level[x+1][y]=level[x][y];
						m.insert(make_pair(make_pair(level[x+1][y],x+1),make_pair(y,temp)));
					}
				}else{
					if(level[x][y]+1 < level[x+1][y]){
						temp.insert(arr[x+1][y]);
						level[x+1][y] = level[x][y]+1;
						m.insert(make_pair(make_pair(level[x+1][y],x+1),make_pair(y,temp)));
						temp.erase(arr[x+1][y]);
					}
				}
			}
			if(y+1<n && !mark[x][y+1]){
				if(temp.find(arr[x][y+1]) != temp.end()){
					if(level[x][y] < level[x][y+1]){
						level[x][y+1]=level[x][y];
						m.insert(make_pair(make_pair(level[x][y+1],x),make_pair(y+1,temp)));
					}
				}else{
					if(level[x][y]+1 < level[x][y+1]){
						temp.insert(arr[x][y-1]);
						level[x][y+1] = level[x][y]+1;
						m.insert(make_pair(make_pair(level[x][y+1],x),make_pair(y+1,temp)));
						temp.erase(arr[x][y-1]);
					}
				}
			}
			if(y-1>=0 && !mark[x][y-1]){
				if(temp.find(arr[x][y-1]) != temp.end()){
					if(level[x][y] < level[x][y-1]){
						level[x][y-1]=level[x][y];
						m.insert(make_pair(make_pair(level[x][y-1],x),make_pair(y-1,temp)));
					}
				}else{
					if(level[x][y]+1 < level[x][y-1]){
						temp.insert(arr[x][y+1]);
						level[x][y-1] = level[x][y]+1;
						m.insert(make_pair(make_pair(level[x][y-1],x),make_pair(y-1,temp)));
						temp.erase(arr[x][y+1]);
					}
				}
			}
		}
	}
}