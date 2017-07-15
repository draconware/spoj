#include<bits/stdc++.h>
using namespace std;

#define LD double
#define SRE(x) (x*x)

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        LD r1,r2,r3,c,d,r,disri;
        cin>>r1>>r2>>r3;

        c=(1/r1)+(1/r2)+(1/r3);
        d=(1/SRE(r1))+(1/SRE(r2))+(1/SRE(r3));

        disri=sqrt((2*SRE(c))-(2*d));
        r=(1/(c+disri));

        printf("%.6lf\n",r);
    }
    return 0;
}
