#include<bits/stdc++.h>
using namespace std;
#define LL long long

int s(LL n,LL m){
    if(n==m)
        return 1;
    if(n < m)
        return 0;
    if(n==0 && m==0)
        return 1;
    if(n==0 || m==0)
        return 0;
    return ((m%2)*s(n-1,m) + s(n-1,m-1));
}

int main(){
    ios_base::sync_with_stdio(false);
    LL d;
    cin>>d;
    while(d--){
        LL n,m;
        cin>>n>>m;
        cout<<((s(n,m))%2)<<endl;
    }
    return 0;
}
