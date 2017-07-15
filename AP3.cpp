#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long
#define LD long double
#define SQRE(x) (x*x)

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
        LL n1,n2,sum,a1,d;
        LD root,n,discri,a,b,c;
        cin>>n1>>n2>>sum;

        a = n1+n2 ;
        b = (7.0*n1)+(5.0*n2)+(2.0*sum) ;
        c = 12.0*sum ;

        discri = SQRE(b)-(4.0*a*c);
        root = sqrt(discri);

        n=(b+root)/(2.0*a);
        LL len = llrintl(n);
        cout<<len<<endl;

        LD diff = (n2-n1)/(len-6.0);
        d=llrintl(diff);

        a=n1-(2*d);

        printall(a,d,len);
    }
    return 0;
}
