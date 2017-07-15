#include<bits/stdc++.h>
using namespace std;

pair<int,int> st[3*100000];
int lazy[3*100000];

void build(int s,int e,int i){
    if(s == e){
        st[i].first = 0;
        st[i].second = 1;
        //cout<<s<<","<<e<<" "<<st[i].first<<","<<st[i].second<<endl;
    }else{
        int m = (s+e)/2;
        build(s,m,2*i+1);
        build(m+1,e,2*i+2);
        st[i].first = st[2*i+1].first + st[2*i+2].first;
        st[i].second = st[2*i+1].second + st[2*i+2].second;
        //cout<<s<<","<<e<<" "<<st[i].first<<","<<st[i].second<<endl;
    }
}

void update(int l,int h,int s,int e,int i){
    if(lazy[i]%2 != 0){
        swap(st[i].first,st[i].second);
        if(s != e){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
            //cout<<"executed1 on"<<i<<" -----updated "<<2*i+1 <<","<<2*i+2<<endl;
        }
        lazy[i]=0;
    }
    if(l>e || s>h){return;}
    if(l<=s && e<=h){
        //cout<<l<<","<<h<<" "<<s<<","<<e<<endl;
        swap(st[i].first,st[i].second);
        if(s != e){
            lazy[2*i+1]++;
            lazy[2*i+2]++;
            //cout<<"executed2 on"<<i<<" -----updated "<<2*i+1 <<","<<2*i+2<<endl;
        }
        return;
    }
    int m=(s+e)/2;
    update(l,h,s,m,2*i+1);
    update(l,h,m+1,e,2*i+2);
    st[i].first = st[2*i+1].first + st[2*i+2].first;
    st[i].second = st[2*i+1].second + st[2*i+2].second;
}
int ans;

void query(int l,int h,int s,int e,int i){
    if(l>e || h<s){return;}
    if(lazy[i]%2){
        swap(st[i].first,st[i].second);
        if(s != e){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i]=0;
    }
    if(l<=s && h>=e){
        ans += st[i].first;
        //cout<<s<<","<<e<<endl;
        return;
    }
    int m=(s+e)/2;
    query(l,h,s,m,2*i+1);
    query(l,h,m+1,e,2*i+2);
}

int main(){
    int n,m,i,x,y;
    scanf("%d %d", &n, &m);

    build(0,n-1,0);
    memset(lazy,0,sizeof(lazy));
    while(m--){
        scanf("%d %d %d", &i, &x, &y);
        if(i){
            ans=0;
            query(x-1,y-1,0,n-1,0);
            printf("%d\n",ans);
        }else{
            update(x-1,y-1,0,n-1,0);
        }
    }
    return 0;
}
