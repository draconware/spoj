#include<bits/stdc++.h>
using namespace std;

#define MAX 1000009

int mark[MAX];
vector<int> v[MAX];
vector<pair<int,int> > query;
int level[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        for(int i=0;i<MAX;i++){v[i].clear();}
        query.clear();
        int n,r,m,x,y;
        cin>>n>>r>>m;

        for(int i=0;i<r;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        bool flag=true;
        memset(mark,0,sizeof(mark));
        memset(level,0,sizeof(level));
        for(int i=0;i<m;i++){
            cin>>x>>y;
            query.push_back(make_pair(x,y));
        }
        for(int i=0;i<m;i++){
            x=query[i].first;y=query[i].second;
            //cout<<x<<","<<y<<endl;
            if(mark[x]!=0 && mark[x] != x){flag=false;break;}
            mark[x]=x;
            queue<int> q;
            q.push(x);
            level[x]=0;
            while(!q.empty()){
                int p = q.front();q.pop();

                for(int j=0;j<v[p].size();j++){
                    if(level[p]+1 > y){continue;}
                    if(mark[v[p][j]] == x){continue;}
                    if(mark[v[p][j]]!=0 && mark[v[p][j]] != x){flag=false;break;}
                    mark[v[p][j]]=x;
                    if(level[p]+1 <= y){q.push(v[p][j]);level[v[p][j]] = level[p]+1;}
                    //cout<<v[p][j]<<" marked "<<x<<endl;
                }
                if(!flag){break;}
            }
            if(!flag){break;}
        }
        if(flag){cout<<"Yes"<<endl;}
        else{cout<<"No"<<endl;}
    }
}
