#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000

vector<int> prime;

void sieve(){
    bool mark[MAX];
    for(int i=3;(i*i)<=MAX;i+=2){
        if(mark[i]==0){
            for(int j=(i*i);j<=MAX;j+=i){
                mark[j]=1;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=MAX;i+=2){
        if(mark[i]==0){
            prime.push_back(i);
        }
    }
}

LL gcd(LL a,LL b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

LL divisors(LL c){
    LL d=c,ans,res=1;
    for(int i=prime[0];(i<prime.size())&&(i*i)<=c;i++){
        ans=1;
        while(!(d%i)){
            ans++;
            d/=i;
        }
        res*=ans;
    }
    if(d!=1){
        res*=2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    sieve();
    LL t;
    scanf("%lld", &t);

    while(t--){
        LL a,b,c,div;
        scanf("%lld %lld", &a, &b);

        c=gcd(a,b);

        div=divisors(c);
        printf("%lld\n",div);
    }
    return 0;
}
