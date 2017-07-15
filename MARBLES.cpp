#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL combi(int n,int k)
{
    if(n==k){
        return 1;
    }
    if(k==0){
        return 1;
    }
    if(k==1){
        return n;
    }
    return combi(n-1,k)+combi(n-1,k-1);
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        LL ans = combi(n-1,k-1);
        cout<<ans<<endl;
    }
    return 0;
}
