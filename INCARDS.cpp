#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000009

vector< pair<LL,LL> > v[MAX];
vector< pair<LL,LL> > v1[MAX];
LL level[MAX];
bool mark[MAX];
LL ans=0;

void dijkstra(){
    memset(mark,0,sizeof(mark));
    fill(level,level+MAX,LONG_LONG_MAX);
    multiset< pair<LL,LL> > m;
    m.insert(make_pair(0,1));level[1]=0;

    while(!m.empty()){
        pair<LL,LL> p = *m.begin();
        m.erase(m.begin());

        LL x = p.second;
        if(mark[x]){continue;}
        mark[x]=true;
        ans+=level[x];

        for(LL i=0;i<v[x].size();i++){
            LL y = v[x][i].second,w = v[x][i].first;
            if(level[x]+w < level[y]){
                level[y] = level[x]+w;
                m.insert(make_pair(level[y],y));
            }
        }
    }
}

void dijkstra1(){
    memset(mark,0,sizeof(mark));
    fill(level,level+MAX,LONG_LONG_MAX);
    multiset< pair<LL,LL> > m;
    m.insert(make_pair(0,1));level[1]=0;

    while(!m.empty()){
        pair<LL,LL> p = *m.begin();
        m.erase(m.begin());

        LL x = p.second;
        if(mark[x]){continue;}
        mark[x]=true;
        ans+=level[x];

        for(LL i=0;i<v1[x].size();i++){
            LL y = v1[x][i].second,w = v1[x][i].first;
            if(level[x]+w < level[y]){
                level[y] = level[x]+w;
                m.insert(make_pair(level[y],y));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL t;
    cin>>t;

    while(t--){
    	ans=0;
        LL n,m,x,y,w;
        cin>>n>>m;
		for(LL i=0;i<MAX;i++){v[i].clear();v1[i].clear();}
        for(LL i=0;i<m;i++){
            cin>>x>>y>>w;
            v[x].push_back(make_pair(w,y));
            v1[y].push_back(make_pair(w,x));
        }

        dijkstra();
        //for(int i=1;i<=n;i++){cout<<level[i]<<" ";}cout<<endl;
        dijkstra1();
        //for(int i=1;i<=n;i++){cout<<level[i]<<" ";}cout<<endl;

        cout<<ans<<endl;
    }
    return 0;
}
