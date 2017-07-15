#include<stdio.h>
#define LL long long
LL gcd(LL x,LL y){
    if(x%y == 0)
        return x;
    else
        return gcd( y%x , x );
}
int main(){
    LL t;
    scanf("%lld", &t);
    while(t--){
        LL a,b,temp;
        scanf("%lld %lld", &a, &b);
        temp=a;
        a /= gcd(a,b);
        b /= gcd(temp,b);
        printf("%lld %lld\n",b,a);
    }
    return 0;
}
