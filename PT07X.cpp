#include<bits/stdc++.h>
using namespace std;

#define MAX 100009

vector<int> v[MAX];
int color[MAX];
bool mark[MAX];

void bfs(int s){
    queue<int> q;
    q.push(s);
    color[s]=1;

    while(!q.empty()){
        int p = q.front();
        q.pop();

        if(mark[p]){continue;}
        mark[p]=true;
        for(int i=0;i<v[p].size();i++){
            if(!mark[v[p][i]]){
                color[v[p][i]] = 1 - color[p];
                q.push(v[p][i]);
            }
        }
    }
}

int main(){
    int n,x,y;
    cin>>n;
    memset(mark,0,sizeof(mark));

    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);

    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        if(color[i]==1){
            ans1++;
        }else{
            ans2++;
        }
    }
    cout<<min(ans1,ans2)<<endl;
}
