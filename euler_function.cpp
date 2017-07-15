#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL euler_function(LL x){
    double result=x;

    for(LL i=2;i*i<=x;i++){
        if(x%i == 0){
        while(x%i == 0){
            x/=i;
            }
        result*=(1.0 - (1.0/(double)i));
        }
    }

    if(x>1){
        result*=(1.0-(1.0/(double)x));
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        LL n,ans;
        cin>>n;

        ans=euler_function(n);
        cout<<ans<<endl;
    }
    return 0;
}
