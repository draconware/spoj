#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    int t,j=1;
    cin>>t;

    while(t--){
        double r;
        cin>>r;

        double ans=4.0*r*r+(1.0/4.0);
        printf("Case %d: %.2lf\n",j,ans);
        j++;
    }
    return 0;
}
