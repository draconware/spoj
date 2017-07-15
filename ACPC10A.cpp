#include<bits/stdc++.h>
using namespace std;

#define LL long long

bool check_ap(LL a,LL b,LL c){
    if(c == ((2*b)-a)){
        return true;
    }
    return false;
}

int main(){
    LL a,b,c;
    while(1){
        cin>>a>>b>>c;
        if((!a)&&(!b)&&(!c)){
            return 0;
        }
        if(check_ap(a,b,c) == true){
            cout<<"AP "<<((3*b)-(2*a))<<endl;
        }else{
            double ans,c;
            c = ((double)b/(double)a);
            ans = (double)a*c*c*c;
            printf("GP %lld\n",(LL)ans);
        }
    }
    return 0;
}
