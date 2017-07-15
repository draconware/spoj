#include<bits/stdc++.h>
using namespace std;

#define MAX 800009
#define RET 1073741823

int st[MAX];

void build(int s,int e,int i,int arr[]){
    if(s == e){
        st[i]=arr[s];
    }else{
        int m = (s+e)/2;
        build(s,m,2*i+1,arr);
        build(m+1,e,2*i+2,arr);

        st[i] = st[2*i+1] & st[2*i+2];
    }
    //cout<<i<<","<<st[i]<<endl;
}

int query(int l,int h,int s,int e,int i){
    if(l>e || h<s){return RET;}
    if(l<=s && h>=e){return st[i];}
    int m = (s+e)/2;

    return (query(l,h,s,m,2*i+1) & query(l,h,m+1,e,2*i+2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++){cin>>arr[i];}

        build(0,n-1,0,arr);
        int l1,h1,l2,h2,c;

        int res[n];
        if(k > n/2){k = n/2;}
        for(int i=0;i<n;i++){
            l1 = (i-k+n)%n;
            h1 = (i-1+n)%n;
            if(l1 > h1){res[i]=query(l1,n-1,0,n-1,0) & query(0,h1,0,n-1,0);}
            else{res[i] = query(l1,h1,0,n-1,0);}
            //cout<<l1<<","<<h1<<","<<res[i]<<endl;
            l2 = (i+1+n)%n;
            h2 = (i+k+n)%n;
            if(l2 > h2){c=query(l2,n-1,0,n-1,0) & query(0,h2,0,n-1,0);}
            else{c = query(l2,h2,0,n-1,0);}
            res[i] = res[i] & arr[i] & c;
            //cout<<l2<<","<<h2<<","<<res[i]<<endl;
        }
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
