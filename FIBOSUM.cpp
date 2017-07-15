#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007

void multiply(LL F[2][2],LL M[2][2]){
    LL x = F[0][0] * M[0][0] + F[0][1] * M[1][0] ;
    x%=MOD;
    LL y = F[0][0] * M[0][1] + F[0][1] * M[1][1] ;
    y%=MOD;
    LL z = F[1][0] * M[0][0] + F[1][1] * M[1][0] ;
    z%=MOD;
    LL w = F[1][0] * M[0][1] + F[1][1] * M[1][1] ;
    w%=MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(LL F[2][2],LL n){
    if(n==0||n==1){
        return;
    }
    LL M[2][2] = {{1,1},{1,0}};
    power(F,n/2);
    multiply(F,F);
    if((n%2) != 0){
        multiply(F,M);
    }
}

LL fib(LL n){
    if(n==0){
        return 0;
    }
    LL F[2][2]={{1,1},{1,0}};
    power(F,n-1);
    return F[0][0];
}

int main(){
    LL t;
    cin>>t;

    while(t--){
        LL n,m;
        cin>>n>>m;
        LL ans=fib(m+2)-fib(n+1);
        ans%=MOD;
        ans = ans<0?(ans+MOD):ans;
        ans%=MOD;
        cout<<ans<<endl;
    }
    return 0;
}
