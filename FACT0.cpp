#include<bits/stdc++.h>
using namespace std;

#define LL long long

void factors(LL n){
    LL count,k=n;
    for(LL i=2;(i*i) <= k;i++){
        count=0;
        if(!(n%i)){
            while(!(n%i)){
                count++;
                n/=i;
            }
            if(count>0){
                cout<<i<<"^"<<count<<" ";
            }
        }
        if(n==1){
            break;
        }
    }
    if(n>1){
        cout<<n<<"^1";
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    while(1){
        LL n;
        cin>>n;
        if(!n){
            return 0;
        }
        if(n<=3){
            cout<<n<<"^1"<<endl;
            continue;
        }
        factors(n);
        cout<<"\n";
    }
}
