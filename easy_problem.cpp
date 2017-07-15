#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    long long t;
    cin>>t;
    for(long long j=1;j<=t;j++){
        long long n,k,ans=0;
        cin>>n>>k;
        long long arr[n];
        for(long long i=0;i<n;i++){
            cin>>arr[i];
            ans+=arr[i];
        }
        ans=(k*(n+1))-ans;
        cout<<"Case "<<j<<": "<<ans<<endl;
    }
    return 0;
}

