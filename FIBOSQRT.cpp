#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    LL t;
    cin>>t;

    while(t--){
        LL c,a,b,n,m;
        cin>>b>>a>>m>>n;

        for(LL i=1;i<n;i++){
            c=a+b+2*(LL)sqrt(3.0+(double)(a*b));
            b=a;
            a=c;
        }
        cout<<c%m<<endl;
    }
    return 0;
}
