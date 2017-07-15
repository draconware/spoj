#include<bits/stdc++.h>
using namespace std;

int mark[1010];

int root(int x){
    if(x != mark[x]){
        x = mark[mark[x]];
    }
    return x;
}

void unite(int x,int y){
    int a = root(x);
    int b = root(y);
    if(a<b){mark[b] = mark[a];}
    else{mark[a] = mark[b];}
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int x,y,w,p,n,m;
        cin>>p>>n>>m;

        pair<int,pair<int,int> > v[m];
        for(int i=0;i<=n;i++){mark[i]=i;}
        for(int i=0;i<m;i++){
            cin>>x>>y>>w;
            v[i] = make_pair(w,make_pair(x,y));
        }
        int ans=0,c = n-1;
        sort(v,v+m);
        for(int i=0;i<m && c>0;i++){
            x = v[i].second.first;y = v[i].second.second;w = v[i].first;
            //cout<<x<<","<<y<<","<<w<<","<<root(x)<<","<<root(y)<<endl;
            if(root(x) != root(y)){
                ans+=w;
                unite(x,y);
                c--;
            }
        }
        cout<< ans*p <<endl;
    }
}
