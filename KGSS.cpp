#include<bits/stdc++.h>
using namespace std;

vector<int> v;
vector< pair<int,int> >st(2*131072);
pair<int,int> res;

void build(int s,int e,int i){
    if(s == e){
        st[i].first = v[s];
        st[i].second = v[s];
    }else{
        int m = (s+e)/2;
        build(s,m,2*i+1);
        build(m+1,e,2*i+2);
        st[i].first = max(st[2*i+1].first,st[2*i+2].first);
        st[i].second = max(st[2*i+1].second,max(st[2*i+2].second,st[2*i+1].first+st[2*i+2].first));
    }
}

void update(int p,int val,int s,int e,int i){
    if(e<p || s>p){return;}
    if(s == p && e == p){
        st[i].first=val;
        st[i].second=val;
        return;
    }
    int m=(s+e)/2;
    update(p,val,s,m,2*i+1);
    update(p,val,m+1,e,2*i+2);
    st[i].first = max(st[2*i+1].first,st[2*i+2].first);
    st[i].second = max(st[2*i+1].second,max(st[2*i+2].second,st[2*i+1].first+st[2*i+2].first));
}

void query(int l,int h,int s,int e,int i){
    if(l>e || s>h){
        //cout<<"executed1"<<endl;
        return;
    }
    if(s>=l && h>=e){
        //cout<<"executed2"<<endl;
        res.second = max(res.first + st[i].first,max(res.second,st[i].second));
        res.first = max(res.first,st[i].first);
        //res.second = max(res.first + st[i].first,max(res.second,st[i].second));
        //cout<<
        return;
    }
    //cout<<"executed3"<<endl;
    int m = (s+e)/2;
    query(l,h,s,m,2*i+1);
    query(l,h,m+1,e,2*i+2);
}

int main(){
    int n,a;
    cin>>n;

    for(int i=0;i<n;i++){cin>>a;v.push_back(a);}
    build(0,n-1,0);
    int m,x,y;
    cin>>m;
    char c;
    while(m--){
        cin>>c>>x>>y;
        if(c=='U'){
            update(x-1,y,0,n-1,0);
        }else{
            res.first=0;res.second=0;
            query(x-1,y-1,0,n-1,0);
            cout<<res.second<<endl;
        }
    }
}
