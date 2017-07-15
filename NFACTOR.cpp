#include<bits/stdc++.h>
using namespace std;
#define SET 1000000
#define LL long long

LL prime[SET],result[SET];

void prime_generator(LL b){
    memset(prime,0,sizeof(prime));
    for(LL i=2;i*2<=b;i++){
        if(prime[i] == 0){
            for(LL j=i*2 ; j<=b ;j+=i)
                prime[j]++;
        }
    }
}

int main(){
    LL t;
    cin>>t;
    while(t--){
        LL a,b,n,ans=0;
        cin>>a>>b>>n;
        if(n==0){
            if(a==1){
                cout<<1<<endl;
                continue;
            }
        }
        if(a==1)
            a=2;
        prime_generator(b);
        factorization(b);
        for(LL i=a;i<=b;i++){
            if(prime[i]-n == 0)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
