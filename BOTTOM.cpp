#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 5009

vector<LL> v[MAX];
vector<LL> v1[MAX];
LL parent[MAX];
bool mark[MAX]={false};
stack<LL> s;

void dfs(LL x){
    mark[x]=true;
    for(LL i=0;i<v[x].size();i++){
        if(!mark[v[x][i]]){
            dfs(v[x][i]);
        }
    }
    s.push(x);
}

LL root(LL x){
    while(x != parent[x]){
        x = parent[parent[x]];
    }
    return x;
}

void unite(LL x,LL y){
    if(x < y){
        parent[y]=parent[x];
    }else{
        parent[x]=parent[y];
    }
}

void dfs1(LL x){
    mark[x]=true;
    for(LL i=0;i<v1[x].size();i++){
        if(!mark[v1[x][i]]){
            LL x1 = root(x);
            LL x2 = root(v1[x][i]);
            if(x1 != x2){
                unite(x1,x2);
            }
            dfs(v1[x][i]);
        }
    }
}

int main(){
    LL n,m;
    while(1){
        cin>>n;
        if(n==0){break;}
        cin>>m;
        LL x,y;
        for(LL i=0;i<MAX;i++){v[i].clear();v1[i].clear();}
        for(LL i=0;i<m;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v1[y].push_back(x);
        }
        for(LL i=0;i<MAX;i++){mark[i]=false;}
        for(LL i=1;i<=n;i++){
            if(!mark[i]){
                dfs(i);
            }
        }
        for(LL i=0;i<MAX;i++){mark[i]=false;parent[i]=i;}
        while(!s.empty()){
            LL x = s.top();
            s.pop();
            if(!mark[x]){
                dfs1(x);
            }
        }
        for(LL i=0;i<MAX;i++){mark[i]=false;}
        vector<LL> res;
        int flag=0;
        for(LL i=1;i<=n;i++){
            if(mark[i]){continue;}
            res.push_back(i);
            for(LL j=0;j<v[i].size();j++){
                if(root(i) != root(v[i][j])){
                    res.clear();
                    break;
                }else{
                    mark[v[i][j]]=true;
                    res.push_back(v[i][j]);
                }
            }
            if(res.size()>0){
                flag=1;
                for(LL k=0;k<res.size();k++){
                    cout<<res[k]<<" ";
                }
            }
        }
        cout<<endl;
    }
}
