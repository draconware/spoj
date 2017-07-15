#include<stdio.h>
#define LL unsigned long long
#define M 100000007
#define X 33333336

LL modular_exponentiation(LL y){
    LL result=1,x=2;

    while(y>0){
        if(y%2 == 1){
            result=(result*x)%M;
        }
        y=y>>1;
        x=(x*x)%M;
    }
    return result;
}

int main(){
    LL n;
    while(scanf("%llu",n) != EOF){
        LL ans=modular_exponentiation(n-1);
        ans=(ans*X)%M;
        printf("%llu\n",ans);
    }
}
