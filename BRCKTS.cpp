#include<bits/stdc++.h>
using namespace std;

#define MAX 32768

struct node{
    int left;
    int right;
};

struct node st[3*MAX];
char arr[MAX];

void build(int s,int e,int i){
    if(s == e){
        if(arr[s] == '('){
            st[i].left = 1;
            st[i].right = 0;
        }else{
            st[i].left = 0;
            st[i].right = 1;
        }
    }else{
        int m = (s+e)/2;
        build(s,m,2*i+1);
        build(m+1,e,2*i+2);

        int c = min(st[2*i+1].left,st[2*i+2].right);
        st[i].left = st[2*i+1].left + st[2*i+2].left - c;
        st[i].right = st[2*i+1].right + st[2*i+2].right - c;
    }
}

void update(int x,int s,int e,int i){
    if(s>x || e<x){return ;}
    if(s == x && e == x){
        if(st[i].left == 1){
            st[i].left = 0;
            st[i].right = 1;
        }else{
            st[i].left = 1;
            st[i].right = 0;
        }
    }else{
        int m = (s+e)/2;
        update(x,s,m,2*i+1);
        update(x,m+1,e,2*i+2);

        int c = min(st[2*i+1].left,st[2*i+2].right);
        st[i].left = st[2*i+1].left + st[2*i+2].left - c;
        st[i].right = st[2*i+1].right + st[2*i+2].right - c;
    }
}

int main(){
    int t=10,c=1;
    while(t--){
        int n;
        cin>>n;

        for(int i=0;i<n;i++){cin>>arr[i];}
        build(0,n-1,0);
        int m,x;
        cin>>m;
        cout<<"Test "<<c<<":"<<endl;
        while(m--){
            cin>>x;
            if(x==0){
                if(st[0].left == 0 && st[0].right == 0){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }else{
                update(x-1,0,n-1,0);
            }
        }
        c++;
    }
}
