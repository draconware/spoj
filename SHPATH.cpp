#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > v[10009];
int level[10009];
bool mark[10009];

void dijkstras(int s){
    for(int i=0;i<10009;i++){level[i]=INT_MAX;mark[i]=false;}
    multiset< pair<int,int> > m;
    m.insert(make_pair(0,s));
    level[s]=0;

    while(!m.empty()){
        pair<int,int> p = *m.begin();
        m.erase(m.begin());

        if(mark[p.second]){continue;}
        int x = p.second;mark[x]=true;
        for(int i=0;i<v[x].size();i++){
            int y = v[x][i].second,w = v[x][i].first;

            if(level[x] + w < level[y]){
                //cout<<x<<","<<y<<","<<w<<endl;
                level[y] = level[x] + w;
                m.insert(make_pair(level[y],y));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n,x,y,w;
        cin>>n;
		for(int i=0;i<=n;i++){v[i].clear();}
        string s,s1;
        map<string,int> m;
        for(int i=0;i<n;i++){
            cin>>s;
            m[s]=i+1;
            cin>>x;
            while(x--){
                cin>>y>>w;
                v[i+1].push_back(make_pair(w,y));
            }
        }
        int q;
        cin>>q;
        while(q--){
            cin>>s>>s1;
            int st = m[s],te = m[s1];

            dijkstras(st);
            cout<<level[te]<<endl;
        }
    }
}
