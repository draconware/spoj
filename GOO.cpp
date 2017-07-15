#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    int t,n;
    cin>>t;

    while(t--){
       cin>>n;

       LL ans1=(LL)pow(2.0,n-1);
       LL ans2=ans1+(n-1)*(ans1/2);

       cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
