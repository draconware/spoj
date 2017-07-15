#include<iostream>
#define LL long long
using namespace std;
int main(){
    LL t,ans,n;
    cin>>t;
    char op;
    while(t--){
        cout<<"\n";
        cin>>ans;
        while(1){
            cin>>op;
            if(op=='=')
                break;
            cin>>n;
            if(op=='+')
                ans=ans+n;
            if(op=='-')
                ans-=n;
            if(op=='*')
                ans*=n;
            if(op=='/')
                ans/=n;
        }
        cout<<ans<<endl;
    }
}
