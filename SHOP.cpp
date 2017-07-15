#include<bits/stdc++.h>
using namespace std;

char v[30][30];
int level[30][30];
bool mark[30][30];

void dijkstra(int n,int m,int sx,int sy){
    multiset< pair<int,pair<int,int> > > mu;
    mu.insert(make_pair(0,make_pair(sx,sy)));
    level[sx][sy]=0;

    while(!mu.empty()){
        pair<int,pair<int,int> > p = *mu.begin();
        mu.erase(mu.begin());
        int x=p.second.first,y=p.second.second;
        if(mark[x][y]){
            continue;
        }
        mark[x][y]=true;
        if(x<m && y-1>=0 && v[x][y-1]=='D'){
            if(level[x][y] < level[x][y-1]){
                level[x][y-1]=level[x][y];
            }
        }
        if(x<m && y+1<n && v[x][y+1]=='D'){
            if(level[x][y] < level[x][y+1]){
                level[x][y+1] = level[x][y];
            }
        }
        if(x+1<m && y<n && v[x+1][y]=='D'){
            if(level[x][y] < level[x+1][y]){
                level[x+1][y] = level[x][y];
            }
        }
        if(x-1>=0 && y<n && v[x-1][y]=='D'){
            if(level[x][y] < level[x-1][y]){
                level[x-1][y] = level[x][y];
                //mu.insert(make_pair(level[x-1][y],make_pair(x-1,y)));
            }
        }
        if(x<m && y-1>=0 && v[x][y-1]!='X' && v[x][y-1]!='S' && v[x][y-1]!='D'){
            if(level[x][y] + (v[x][y-1]-'0') < level[x][y-1]){
                level[x][y-1] = level[x][y] + (v[x][y-1]-'0');
                mu.insert(make_pair(level[x][y-1],make_pair(x,y-1)));
            }
        }
        if(x<m && y+1<n && v[x][y+1]!='X' && v[x][y+1]!='S' && v[x][y+1]!='D'){
            if(level[x][y] + (v[x][y+1]-'0') < level[x][y+1]){
                level[x][y+1] = level[x][y] + (v[x][y+1]-'0');
                mu.insert(make_pair(level[x][y+1],make_pair(x,y+1)));
            }
        }
        if(x+1<m && y<n && v[x+1][y]!='X' && v[x+1][y]!='S' && v[x+1][y]!='D'){
            if(level[x][y] + (v[x+1][y]-'0') < level[x+1][y]){
                level[x+1][y] = level[x][y] + (v[x+1][y]-'0');
                mu.insert(make_pair(level[x+1][y],make_pair(x+1,y)));
            }
        }
        if(x-1>=0 && y<n && v[x-1][y]!='X' && v[x-1][y]!='S' && v[x-1][y]!='D'){
            if(level[x][y] + (v[x-1][y]-'0') < level[x-1][y]){
                level[x-1][y] = level[x][y] + (v[x-1][y]-'0');
                mu.insert(make_pair(level[x-1][y],make_pair(x-1,y)));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,sx,sy,dx,dy;
    while(1){
        cin>>n>>m;
        if(n==0 && m==0){return 0;}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                level[i][j]=INT_MAX;
                mark[i][j]=false;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
                if(v[i][j] == 'S'){sx = i;sy = j;}
                if(v[i][j] == 'D'){dx = i;dy = j;}
            }
        }
        dijkstra(n,m,sx,sy);
        cout<<level[dx][dy]<<endl;
    }
}
