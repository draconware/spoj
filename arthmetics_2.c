#include<stdio.h>
#include<stdlib.h>
#define LL long long
int main(){
    LL t;
    scanf("%lld", &t);
    while(t--){
        LL n,ans;
        scanf("%lld", &n);
        ans=(LL)sqrt((double)n);
        printf("%lld\n", ans);
    }
    return 0;
}

