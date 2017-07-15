#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL power(LL a,LL b){
    LL ans=a;
    for(LL i=0;i<b;i++){
        ans*=a;
    }
    return (ans%10);
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[10]={0,1,4,4,2,1,1,4,4,2};
    int t;
    cin>>t;
    while(t--){
        LL a,b;
        cin>>a>>b;
        a%=10;
        if(a==0){
            cout<<"0"<<endl;
            continue;
        }
        if(b==0){
            cout<<"1"<<endl;
            continue;
        }
        b--;
        b-=((b/arr[a])*arr[a]);
        cout<<power(a,b)<<endl;
    }
    return 0;
}
