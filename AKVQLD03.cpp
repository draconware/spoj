#include<bits/stdc++.h>
using namespace std;

#define N 4000005
int st[N]={0};

int n,k;
void update(int p,int x){
    for(;p<=n;p += (p&(-p))){
        st[p] += x;
    }
}

int query(int l){
    int sum=0;
    for(;l>0;l -= (l&(-l))){
        //cout<<"position is---- "<<l<<" sum is--- "<<sum<<endl;
        sum += st[l];
    }
    return sum;
}

int main(){
    cin>>n>>k;

    string s;
    int x,y;
    while(k--){
        cin>>s;

        if(s == "add"){
            cin>>x>>y;
            update(x,y);
        }else{
            cin>>x>>y;
            int ans = ( query(y) - query(x-1) );
            cout<<ans<<endl;
        }
    }
}
