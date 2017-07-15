#include<stdio.h>
#define LL long long

LL totient_function(LL n){
    LL i;
    long double result=n;
    for(i=2; i*i <= n ; i++){
        while(n%i == 0){
          	result *= (1.0-(1.0/(long double)i));
          	printf("%lld ",(LL)result);
            n/=i;
            printf("%lld ",n);
        }
    }
    return (LL)result;
}

int main(){
    LL t;
    scanf("%lld", &t);

    while(t--){
        LL n;
        scanf("%lld", &n);
        LL ans=totient_function(n);

        printf("%lld\n",ans);
    }
    return 0;
}
