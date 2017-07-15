#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long

void printall(LL a,LL d,LL n){
    for(LL i=1;i<=n;i++){
        cout<<a<<" ";
        a+=d;
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        LL n1,n2,sum,a,d,n;
        cin>>n1>>n2>>sum;

        n=((2*sum)/(n1+n2));
        cout<<n<<endl;

        d=((n2-n1)/(n-5));

        a=n1-(2*d);

        printall(a,d,n);
    }
    return 0;
}
