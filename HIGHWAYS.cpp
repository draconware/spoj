#include<bits/stdc++.h>
using namespace std;

#define MAX 100009

vector< pair<int,int> > v[MAX];
int level[MAX];
bool mark[MAX];

void dijkstra(int s){
    multiset<pair<int,int> > m;
    m.insert(make_pair(0,s));
    level[s]=0;

    while(!m.empty()){
        pair<int,int> p = *m.begin();
        m.erase(m.begin());

        int x = p.second;
        if(mark[x]){continue;}
        mark[x]=true;

        for(int i=0;i<v[x].size();i++){
            int y = v[x][i].first,w = v[x][i].second;
            if(level[x] + w < level[y]){
                level[y] = level[x]+w;
                m.insert(make_pair(level[y],y));
            }
        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m,s,e,x,y,w;
        cin>>n>>m>>s>>e;

        for(int i=0;i<MAX;i++){
            level[i]=INT_MAX;
            mark[i]=false;
        }

        for(int i=0;i<m;i++){
            cin>>x>>y>>w;
            v[x].push_back(make_pair(y,w));
            v[y].push_back(make_pair(x,w));
        }
        dijkstra(s);
        if(mark[e]){
            cout<<level[e]<<endl;
        }else{
            cout<<"NONE"<<endl;
        }
    }
    return 0;
}
