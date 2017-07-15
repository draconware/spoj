#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 10009

vector<int> v[MAX];
bool mark[MAX];
bool flag=true;

void dfs(int s,int parent){
    //cout<<"executed"<<endl;
    if(!flag){return;}
    mark[s]=true;
    for(int i=0;i<v[s].size();i++){
        if(v[s][i] != parent){
            if(mark[v[s][i]]){flag=false;return;}
            dfs(v[s][i],s);
        }
    }
}

int main(){
    int n,m,x,y;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(m != n-1){cout<<"NO"<<endl;return 0;}
    if(m == 0){cout<<"YES"<<endl;return 0;}
    memset(mark,0,sizeof(mark));
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(!mark[i]){flag=false;}
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
