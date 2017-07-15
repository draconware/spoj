#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL power(LL x,LL y,LL m){
    LL res=1;

    while(y){
        if(y&1){
            res=(res*x)%m;
        }
        x=(x*x)%m;
        y>>=1;
    }
    return res;
}

LL inverse(LL a,LL b){
    return power(a,b-2,b);
}

int main(){
	ios_base::sync_with_stdio(false);
    LL t,n,p,ans;
    cin>>t;

    while(t--){
        ans=-1;
        cin>>n>>p;

        if(n>=p){
            cout<<"0"<<endl;
        }else if(n == p-1){
            cout<<p-1<<endl;
        }else{
            for(LL i=n+1;i<p;i++){
                ans*=inverse(i,p);
                ans%=p;
            }
            ans+=p;
            ans%=p;
            cout<<ans<<endl;
        }
    }
    return 0;
}
