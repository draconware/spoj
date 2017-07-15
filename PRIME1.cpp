#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL m,n;

void sieve(LL n,vector<LL> &prime){
    bool mark_prime[n+1];
    memset(mark_prime,true,sizeof(mark_prime));

    for(LL i=3;(i*i)<=n;i+=2){
        if(mark_prime[i]==true){
            for(LL j=(i*i);j<=n;j+=i){
                mark_prime[j]==false;
            }
        }
    }
    prime.push_back(2);
    for(LL i=3;i<=n;i+=2){
        if(mark_prime[i]==true){
            prime.push_back(i);
        }
    }
    for(LL i=0;i<prime.size();i++){
        if(prime[i]>=m){
            cout<<prime[i]<<endl;
        }
    }
}

void segmented_sieve(){
    LL limit = floor(sqrt((double)n)) + 1;
    vector<LL> prime;
    sieve(limit,prime);

    LL low = limit;
    LL high = 2*limit;

    while(low < n){
        bool mark_coprime[limit+1];
        memset(mark_coprime,true,sizeof(mark_coprime));

        for(LL i=0;i<prime.size();i++){
            LL lowlimit = (limit/prime[i])*prime[i];
            if(lowlimit < low){
                lowlimit+=prime[i];
            }

            for(LL j=lowlimit;j<high;j+=prime[i]){
                mark_coprime[j-low]=false;
            }
        }
        for(LL c=low;c < high;c++){
            if(mark_coprime[c-low]==true){
                if(c>=m){
                    cout<<c<<endl;
                }
            }
        }
        low+=limit;
        high+=limit;
        if(high>n){
            high=n;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;

        segmented_sieve();
        cout<<endl;
    }
    return 0;
}
