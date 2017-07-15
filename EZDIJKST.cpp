#include<bits/stdc++.h>
using namespace std;

#define MAX 10009

vector< pair<int,int> > v[MAX];
int level[MAX];
bool mark[MAX];

void dijkstra(int s){
    multiset< pair<int,int> > m;
    m.insert(make_pair(0,s));
    level[s]=0;

    while(!m.empty()){
        //cout<<"executed"<<endl;
        pair<int,int> p = *m.begin();
        m.erase(m.begin());
        int x = p.second;
        if(mark[x]){continue;}
        mark[x]=true;
        //cout<<x<<" "<<v[x].size()<<endl;
        for(int i=0;i<v[x].size();i++){
            int y = v[x][i].second,w = v[x][i].first;
            //cout<<y<<","<<w<<","<<level[x]<<","<<level[y]<<endl;
            if(level[x] + w < level[y]){
                //cout<<"executed"<<endl;
                level[y] = level[x] + w;
                m.insert(make_pair(level[y],y));
            }
        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m,x,y,z;
        cin>>n>>m;

        for(int i=1;i<MAX;i++){v[i].clear();level[i]=INT_MAX;mark[i]=false;}
        for(int i=0;i<m;i++){
            cin>>x>>y>>z;
            v[x].push_back(make_pair(z,y));
        }
        cin>>x>>y;
        dijkstra(x);

        if(mark[y]){
            cout<<level[y]<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
