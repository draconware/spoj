#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 209

vector<int> v[MAX];
set<int> e;
int n;

bool bfs(int s){
    queue< pair<int,int> > q;
    pair<int,int> p;
    q.push(make_pair(s,1));

    while(!q.empty()){
        p = q.front();
        if(p.first == n){
            if(e.find(p.second) != e.end()){
                continue;
            }else{
                e.insert(p.second);
                return true;
            }
        }
        for(int i=0;i<v[p.first].size();i++){
            q.push(make_pair(v[p.first][i],p.first));
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>n;

        int x,y,ans=0;
        for(int i=1;i<=n-1;i++){
            cin>>x;
            while(x--){
                cin>>y;
                v[x].push_back(y);if(i==1 && y==n){ans++;}
            }
        }

        for(int i=0;i<v[1].size();i++){
            if(bfs(v[1][i])){
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<n-1;i++){
            v[i].clear();
        }
        e.clear();
    }
    return 0;
}
