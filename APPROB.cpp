#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL gcd(LL a,LL b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        LL n;
        cin>>n;
        LL pd=0,nd=0,num,deno;

        deno=(6*n*n*n);
        LL temp=(n*(n+1))/2;

        pd=(((3*n*n)-temp)/2)-(n/4)+n;
        nd=(((n*n)-temp)/2)-(n/4);
        num=pd+nd;

        LL temp1=gcd(num,deno);
        num/=temp1;
        deno/=temp1;

        cout<<num<<"/"<<deno<<endl;
    }
    return 0;
}
