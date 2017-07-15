#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define M 1000007

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        LL n,ans;
        cin>>n;

        ans=((n*(n+1))%M)+(((n*(n-1))/2)%M);
        ans%=M;
        cout<<ans<<endl;
    }
    return 0;
}
