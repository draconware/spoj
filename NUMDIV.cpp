#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL divisors(LL n){
    LL i,m,ans=1,res=1,k=n;
    for( i=2; (i*i) <= k ;i++){
        ans=1;
        if((n%i) == 0){
            while((n%i) == 0){
                ans++;
                n/=i;
            }
            res*=ans;
            m=i;
        }
        if(n==1){
            break;
        }
    }
    if(n>1){
        res*=2;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        LL n;
        cin>>n;

        LL ans = divisors(n);
        cout<<ans<<endl;
    }
    return 0;
}
