#include<stdio.h>
#define LL long long

LL gcd(LL x,LL y){
    if(y%x == 0)
        return x;
    else
        return gcd( y%x , x );
}
int main(){
    LL t;
    scanf("%lld", &t);
    while(t--){
        LL a,b,x,y;
        scanf("%lld %lld", &a, &b);
        y=(a/gcd(a,b));
        x=(b/gcd(a,b));
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
