#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define S(x) scanf("%lld", &x);

LL power(LL x,int y,LL p){
    LL res=1;
    x%=p;
    while(y){
        if(y&1){
            res = (res*x)%p;
        }
        y>>=1;
        x=(x*x)%p;
    }
    return res;
}

bool miller_test(LL n,int d,int r){
    int m=1;
    LL a = 2 + ( rand() % (n-4));
    LL x = power(a,d,n);

    if(x==1 || x==n-1){
        return true;
    }
    while(m<r){
        x=(x*x)%n;
        m++;
        if(x==1)
            return false;
        if(x==n-1)
            return true;
    }
    return false;
}

bool check(LL n){
    if(n<=3){
        if(n==1){
            return false;
        }
        return true;
    }
    if(!(n%2)){
        return false;
    }
    int d,r=0;
    LL c=n-1;

    while(!(c%2)){
        r++;
        c/=2;
    }
    d = c;

    for(int i=0;i<1;i++){
        if(miller_test(n,d,r)==false){
            return false;
        }
    }
    return true;
}

int main(){
    LL t;
    S(t);

    while(t--){
        LL n;
        S(n);
        if(check(n)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
