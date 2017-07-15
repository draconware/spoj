#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        LL n,a,ans=0;
        cin>>n;
        for(LL i=1;i <= n;i++){
            cin>>a;
            LL temp=(((2*i)-1-n)*a);
            ans+=temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
