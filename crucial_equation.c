#include<stdio.h>
#define LL long long

LL gcd(LL x,LL y){
    if(y%x == 0)
        return x;
    return gcd( y%x , x );
}
int main(){
    LL t,i;
    scanf("%lld", &t);
    for(i=1;i<=t;i++){
        LL a,b,c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if(c%gcd(a,b) == 0)
            printf("Case %lld: Yes\n",i);
        else
            printf("Case %lld: No\n",i);
    }
}
