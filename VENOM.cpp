#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        LL ans;
        double h,p,a,x;
        scanf("%lf %lf %lf", &h, &p, &a);

        x = (p-2.0*a)*(p-2.0*a) + 8*(h-a)*p ;
        double temp;

        temp = (2.0*a - p) + sqrt(x) ;
        temp = temp /(p*2.0) ;

        ans = (LL)ceil(temp);

        if(ans<=0){
            ans=1;
        }

        printf("%lld\n", 2*ans-1 );
    }
}
