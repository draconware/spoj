#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 500000

LL sum_divisors(LL n){
    LL m=n,k,result=1,ans;
    for(LL i=2;(i*i)<=n;i++){
        ans=1,k=i;
        while(!(m%i)){
            ans+=k;
            m/=i;
            k*=i;
        }
        result*=ans;
    }
    if(m>1){
        result*=(m+1);
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
        if(n==1){
            cout<<"0"<<endl;
            continue;
        }
        if(n<=3){
            cout<<"1"<<endl;
        }else{
            LL ans =(sum_divisors(n) - n);
            cout<<ans<<endl;
        }
    }
    return 0;
}
