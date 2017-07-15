#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005
#define LL long long

LL arr[MAX];

void sieve(){
    for(LL i=2;i<MAX;i++){
        arr[i]=1;
    }
    for(LL i=2;i<MAX;i++){
        if(arr[i]==1){
            LL k,ans;
            for(LL j=(i*2);j<MAX;j+=i){
                k=i,ans=1;
                while(!(j%k)){
                    ans+=k;
                    k*=i;
                }
                arr[j]*=ans;
            }
        }
    }
}

int main(){
    sieve();

    int t;
    scanf("%d", &t);

    while(t--){
        LL n,total=0;
        scanf("%lld", &n);

        for(LL i=2;i<=n;i++){
            if(arr[i]==1){
                total++;
            }else{
                total+=(arr[i]-i);
            }
        }
        printf("%lld\n",total);
    }
    return 0;
}
