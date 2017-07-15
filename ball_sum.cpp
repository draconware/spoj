#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define LL long long
LL gcd(LL x,LL y){
    if((y%x) == 0)
        return x;
    return gcd((y%x),x);
}
int main(){
    while(1){
        LL n,k,p,q,temp;
        scanf("%lld %lld", &n, &k);
        if(n==-1 && k==-1)
            break;
        if(n<2){
            printf("0\n");
            continue;
        }
        temp=(k-1)/2;
        p = 2*(k*temp - (temp*(temp+1)));
        q = (n*(n-1)) ;
        if(p==0){
            printf("0\n");
            continue;
        }
        temp=p;
        p/=gcd(p,q);
        q/=gcd(temp,q);
        if(p==q){
            printf("1\n");
            continue;
        }
        printf("%lld/%lld\n",p,q);
    }
    return 0;
}
