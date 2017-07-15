#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,i=1;
    cin>>t;

    while(i<=t){
        int n;
        cin>>n;

        int ans = 3*(n)*(n+1)/2 ;

        cout<<"Case #"<<i<<": "<<ans<<endl;
        i++;
    }
    return 0;
}
