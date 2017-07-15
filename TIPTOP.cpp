#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t,i=1;
    scanf("%d", &t);

    while(i<=t){
        LL n;
        scanf("%lld", &n);

        if(n==1){
            cout<<"Case "<<i<<": Yes"<<endl;
        }else{
            LL x = (LL)floor(sqrt(n));
            if(x*x == n){
                cout<<"Case "<<i<<": Yes"<<endl;
            }else{
                cout<<"Case "<<i<<": No"<<endl;
            }
        }
        i++;
    }
    return 0;
}
