#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL arr[50009];
vector< pair<LL,LL> > st(200009);
LL ans=0,maxi=LONG_LONG_MIN;

void build(LL s,LL e,LL i){
    if(s == e){
        st[i].first = arr[s];
        st[i].second = arr[s];
    }else{
        LL m = (s+e)/2;
        build(s,m,2*i+1);
        build(m+1,e,2*i+2);
        st[i].first = st[2*i+1].first + st[2*i+2].first;
        st[i].second = max(st[i].first,max(st[2*i+1].second,st[2*i+2].second));
    }
}

void query(LL l,LL h,LL s,LL e,LL i){
    if(s>h || l>e){
        return;
    }
    if(s>=l && h>=e){
        ans += st[i].first;
        maxi = max(maxi,st[i].second);
        return;
    }
    LL m = (s+e)/2;
    query(l,h,s,m,2*i+1);
    query(l,h,m+1,e,2*i+2);
}

void update(LL p,LL x,LL s,LL e,LL i){
    if(s>p || e<p){return;}
    if(s == p && e == p){
        st[i].first = x;
        st[i].second = x;
    }else{
        LL m = (s+e)/2;
        update(p,x,s,m,2*i+1);
        update(p,x,m+1,e,2*i+2);

        st[i].first = st[2*i+1].first + st[2*i+2].first;
        st[i].second = max(st[i].first,max(st[2*i+1].second,st[2*i+2].second));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL n;
    cin>>n;

    for(LL i=0;i<n;i++){cin>>arr[i];}
    build(0,n-1,0);

    LL m,j,x,y;
    cin>>m;
    while(m--){
        ans=0;maxi=LONG_LONG_MIN;
        cin>>j>>x>>y;
        if(j==1){
            query(x-1,y-1,0,n-1,0);
            cout<<max(ans,maxi)<<endl;
        }else{
            update(x-1,y,0,n-1,0);
        }
    }
    return 0;
}
