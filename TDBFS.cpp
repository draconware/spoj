#include<bits/stdc++.h>
using namespace std;

#define MAX 1009

vector<int> v[MAX];
bool mark[MAX];

void bfs(int s){
    memset(mark,0,sizeof(mark));
    queue<int> q;
    q.push(s);mark[s]=true;

    while(!q.empty()){
        int p = q.front();q.pop();
        cout<<p<<" ";

        for(int i=0;i<v[p].size();i++){
            if(!mark[v[p][i]]){
                mark[v[p][i]]=true;
                q.push(v[p][i]);
            }
        }
    }
}

void dfs(int s){
    cout<<s<<" ";
    mark[s]=true;
    for(int i=0;i<v[s].size();i++){
        if(!mark[v[s][i]]){
            dfs(v[s][i]);
        }
    }
}

int main(){
    int t,c=0;
    cin>>t;

    while(t--){
        c++;
        int n,x,y,z;
        cin>>n;

        for(int i=0;i<=n;i++){v[i].clear();}

        for(int i=1;i<=n;i++){
            cin>>x>>y;
            while(y--){
                cin>>z;
                v[x].push_back(z);
            }
        }
        cout<<"graph "<<c<<endl;
        while(1){
            cin>>x>>y;
            if(x==0 && y==0){break;}
            if(y==0){
                memset(mark,0,sizeof(mark));
                dfs(x);
            }else{
                bfs(x);
            }
            cout<<endl;
        }
    }
    return 0;
}
