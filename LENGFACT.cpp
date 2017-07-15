#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define TERM log(10.0)
#define E 2.71828182845
#define PI 3.1415926535

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        double n;
        cin>>n;
        if(n<=1.0){
            cout<<"1"<<endl;
            continue;
        }
        double temp=(log(n)/TERM);
        double val=n*(temp-(1.0/TERM))+0.5*(temp+(log(2.0*PI)/TERM));
        LL ans=ceil(val);
        cout<<ans<<endl;
    }
    return 0;
}
