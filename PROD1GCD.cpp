#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define M 1000000007
#define SQRE(x) ((x)*(x))

LL modular_exponentiation(LL x,LL y){
    LL res=1;

    while(y>0){
        if(y & 1){
            res=(res*x)%M;
        }

        y=y>>1;

        x=(x*x)%M;
    }

    return res;
}

LL precomputation(LL m,LL n,LL a){
        for(LL i=a;i<=n;i+=a){
            LL c=m,d=n;
            c-=(m%i);
            d-=(n%i);
            ans-=
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        LL m,n;
        cin>>n>>m;

        LL res=1,power=0;

        for(LL i=2;i<=n;i++){
            cout<<i<<",";
            power=precomputation(m,n,i);
            cout<<power<<",";
            res*=(modular_exponentiation(i,power));
            cout<<res<<endl;
            res%=M;
        }
        cout<<res<<endl;
    }
    return 0;
}
