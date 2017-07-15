#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL gcd(LL a,LL b){
    while(a){
        LL temp=a;
        a=(b-(b/a)*a);
        b=temp;
    }
    return b;
}


int main(){
    LL ans=gcd(24,16);
    cout<<ans;
}
