#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 109
vector<pair<LL,LL> > v[MAX];
LL level[MAX];
bool mark[MAX]={false};

void dijkstras(LL s){
    multiset< pair<LL,LL> > m;
    pair<LL,LL> p;
    m.insert(make_pair(0,s));
    level[s]=0;

    while(!m.empty()){
        p = *m.begin();
        m.erase(m.begin());
        int x = p.second;
        if(mark[x]){
            continue;
        }
        //cout<<"element--- "<<x<<endl;
        mark[x]=true;
        for(int i=0;i<v[x].size();i++){
            int y = v[x][i].first,w = v[x][i].second;
            //cout<<"children and weight--- "<<y<<","<<x<<endl;
            if(level[x]+w < level[y]){
                level[y] = level[x]+w;
                m.insert(make_pair(level[y],y));
            }
        }
    }
}

int main(){
    LL n,m,e,t,x,y,w;
    cin>>n>>e>>t>>m;
    for(LL i=0;i<m;i++){
        cin>>x>>y>>w;
        v[y].push_back(make_pair(x,w));
    }
    for(LL i=0;i<MAX;i++){
        level[i]=1e18;
        mark[i]=false;
    }
    dijkstras(e);
    LL ans=0;
    for(LL i=1;i<=n;i++){
        if(level[i] <= t){
            ans++;
        }
    }
    cout<<ans<<endl;
}
