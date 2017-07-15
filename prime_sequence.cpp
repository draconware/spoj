#include<bits/stdc++.h>
using namespace std;

#define SET 10000001
#define LL long long

LL prime[SET]={0};
void sieve(){
    LL i;
    for(i=2;i*i<=SET;i++){
        if(prime[i] == 0){
            for(LL j=i*i;j<=SET;j+=i){
                if(prime[j] == 0)
                    prime[j]=(j-i);

            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;
    sieve();
    while(t--){
        LL n,ans=0;
        cin>>n;
        ans = ((n*(n+1))/2) -1 ;
        for(LL i=2;i<=n;i++){
            ans-=prime[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
