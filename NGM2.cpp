#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
    LL n,k;
    cin>>n>>k;
    LL prime[n],m,ans=n;
    memset(prime,0,sizeof(prime));
    for(LL i=0;i<k;i++){
        cin>>m;
        if(prime[m]  == 0){
            ans--;
            cout<<ans<<" ";
            prime[m]--;
            for(LL j=m*2; j <= n ;j += m){
                if(prime[j] == 0){
                    prime[j]--;
                    --ans;
                    cout<<ans<<" "<<j<<" "<<endl;
                }
            }
            cout<<ans<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
