#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define SQRE(x) ((x)*(x))
void polynomial(LL n){
    LL ans = ((SQRE(n+1))+(4.0*(SQRE(n))));
    if(floor(sqrt((double)ans)) == ceil(sqrt((double)ans))){
        cout<<"1"<<endl;
    }else{
        cout<<"0"<<endl;
    }
}

int main(){
    LL t;
    cin>>t;

    while(t--){
        LL n;
        cin>>n;

        polynomial(n);
    }
    return 0;
}
