#include<bits/stdc++.h>
using namespace std;

#define LL long long

void build(LL arr[],LL st[],LL s,LL e,LL i){
    if(s == e){
        st[i]=arr[s];
    }else{
        LL m = (s+e)/2;
        build(arr,st,s,m,2*i+1);
        build(arr,st,m+1,e,2*i+2);

        st[i] = st[2*i+1] + st[2*i+2];
    }
}

LL query(LL st[],LL l,LL h,LL s,LL e,LL i){
    if(l>e || h<s){return 0;}
    if(l<=s && h>=e){return st[i];}

    LL m = (s+e)/2;
    return query(st,l,h,s,m,2*i+1) + query(st,l,h,m+1,e,2*i+2);
}

void update(LL st[],LL x,LL s,LL e,LL i){
    if(x<s || x>e){return;}
    if(x == s && x == e){
        st[i] = (LL)sqrt(st[i]);
    }else{
        LL m = (s+e)/2;
        update(st,x,s,m,2*i+1);
        update(st,x,m+1,e,2*i+2);
        st[i] = st[2*i+1] + st[2*i+2];
    }
    cout<<s<<","<<e<<","<<st[i]<<endl;
}

int main(){
    LL n,c=1;
    while(scanf("%lld", &n) != EOF){
        LL arr[n];
        for(LL i=0;i<n;i++){scanf("%lld", &arr[i]);}

        LL max_size = 2*((LL)pow(2,floor(log2(n))))-1;
        LL st[max_size];
        build(arr,st,0,n-1,0);

        LL m,x,y,j;
        cin>>m;
        cout<<"Case #"<<c<<":"<<endl;
        while(m--){
            cin>>j>>x>>y;
            if(j==1){
                cout<<query(st,min(x,y)-1,max(x,y)-1,0,n-1,0)<<endl;
            }else{
                for(LL i=min(x,y)-1;i<=max(x,y)-1;i++){
                    update(st,i,0,n-1,0);
                }
            }
        }
        c++;
    }
    return 0;
}
