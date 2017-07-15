#include<bits/stdc++.h>
using namespace std;

#define MAX 2009

vector<int> v[MAX];
bool mark[MAX];
int color[MAX];

bool bfs(int s){
    queue<int> q;
    q.push(s);
    color[s]=1;

    while(!q.empty()){
        int p = q.front();
        q.pop();

        if(mark[p]){continue;}
        mark[p]=true;

        for(int i=0;i<v[p].size();i++){
            int y = v[p][i];
            if(!mark[y]){
                color[y]=1-color[p];
                q.push(y);
            }else{
                if(color[y] == color[p]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    int t,c=0;
    cin>>t;

    while(t--){
        c++;
        int x,y,n,m;
        cin>>n>>m;

        for(int i=0;i<MAX;i++){
            v[i].clear();
            mark[i]=false;
            color[i]=-1;
        }

        for(int i=0;i<m;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            if(!mark[i]){
                if(!bfs(i)){
                    flag=0;
                    break;
                }
            }
        }
        if(flag){cout<<"Scenario #"<<c<<":\n"<<"No suspicious bugs found!"<<endl;}
        else{cout<<"Scenario #"<<c<<":\n"<<"Suspicious bugs found!"<<endl;}
    }
}
