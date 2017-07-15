#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL knife_cut(LL n){
    double i=0.0;
    while(1){
        if(n<=floor(pow(2.0,i))){
            break;
        }
        i+=1.0;
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    LL a,b,c,sum1,sum2,j=1;
    while(t--){
        cin>>a>>b>>c;

        sum1 = a-1+(a*(b-1))+(a*b*(c-1));
        sum2 = knife_cut(a)+knife_cut(b)+knife_cut(c);

        cout<<"Case #"<<j<<": "<<sum1<<" "<<sum2<<endl;
        j++;
    }
    return 0;
}
