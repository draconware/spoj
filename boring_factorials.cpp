#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL factorial(LL x,LL y){
    for(LL i = (x-1); i>=1 ; i--){
        x = (x*i)%y ;
        if(x==0)
            break;
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(false);
    LL t;
    cin>>t;
    while(t--){
        LL n,k;
        cin>>n>>k;
        cout<<factorial(n,k)<<endl;
    }
}
