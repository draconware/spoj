#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1001050

LL number_of_prime[MAX];
vector<LL> prime;
bool mark[MAX];

void sieve(){
    for(LL i=2;(i*i)<MAX;i++){
        if(!mark[i]){
            for(LL j=(i*i);j<MAX;j+=i){
                mark[j]=1;
            }
        }
    }
    for(LL i=2;i<MAX;i++){
        if(!mark[i]){
            prime.push_back(i);
        }
    }

    vector<LL>::iterator it=prime.begin();
    for(LL i=1;it!=prime.end();it++,i++){
        number_of_prime[i]=(*it);
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    sieve();
    LL t;
    cin>>t;

    while(t--){
        LL n,k,ans=0;
        cin>>n>>k;
        if(k){
            for(LL i=2;i<=n;i++){
                LL m=number_of_prime[k];
                if(m<=n){
                    ans+=(n-m+1);
                }else{
                    break;
                }
                if(!mark[i]){
                    k++;
                }
            }
            cout<<ans<<endl;
        }else{
            LL ans=(n*(n-1))/2;
            cout<<ans<<endl;
        }
    }
    return 0;
}
