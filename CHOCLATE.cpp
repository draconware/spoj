#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,n,wrappers=0,amount=0;
        cin>>a>>b>>n;

        if(n<a){
            cout<<"0"<<endl;
        }else{
            amount+=(n/a);
            wrappers+=amount;

            while( wrappers >= b ){
                amount+=(wrappers/b);
                wrappers = (wrappers/b) + (wrappers%b) ;
            }
            cout<<amount<<endl;
        }
    }
    return 0;
}
