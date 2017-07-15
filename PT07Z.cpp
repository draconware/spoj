#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y;
    cin>>n;

    vector<int> v[n+9];
    for(int i=1;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int s;
    bool mark[n+9];
    memset(mark,0,sizeof(mark));
    queue< int > q;
    q.push(1);

    while(!q.empty()){
        int p = q.front();q.pop();
        mark[p]=true;

        for(int i=0;i<v[p].size();i++){
            if(!mark[v[p][i]]){
                q.push(v[p][i]);
                s=v[p][i];
            }
        }
    }
    //cout<<s<<endl;
    memset(mark,0,sizeof(mark));
    queue< pair<int,int> > q1;
    q1.push(make_pair(s,0));
    int ans=0;
    while(!q1.empty()){
        pair<int,int> p = q1.front();q1.pop();
        mark[p.first]=true;

        for(int i=0;i<v[p.first].size();i++){
            if(!mark[v[p.first][i]]){
                q1.push(make_pair(v[p.first][i],p.second + 1));
                ans = max(ans,p.second + 1);
            }
        }
    }
    cout<<ans<<endl;
}
