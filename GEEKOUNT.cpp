#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    while(n){
        int x = (n%10);
        if(!(x%2)){
            return true;
        }
        n/=10;
    }
    return false;
}

int even(int x){
    if(!(x%2)){
        x--;
    }
    int amount=0;
    while(x>0){
        if(check(x)){
            amount+=((1+(x%10))/2);
        }
        x-=( x%10 + 1 );
    }
    return amount;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int l,r;
        cin>>l>>r;

        int total1=0,total2=0,total=0;

        if(!(l%2)){
            total1+=(l/2);
        }else{
            total1+=((l-1)/2);
        }
        total1 += even(l);

        if(!(r%2)){
            total2+=(r/2);
        }else{
            total2=((r-1)/2);
        }
        total2 += even(r);

        total = total2 - total1;
        if(check(l)){
            total++;
        }

        cout<<total<<endl;
    }
}
