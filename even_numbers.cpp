#include<iostream>
using namespace std;
#define LL long long
int main(){
    LL t,n;
    cin>>t;
    while(t--){
        cin>>n;
        LL ans=0,value=0;
        if(n%2 == 0){
            for(int i=16777216,j=1;n>0; i=i>>1){
                if(n/i != 0 && value==0){
                    j=1;
                    value++;
                }
                if(n/i != 0){
                    ans+=j;
                    n=n%i;
                }
                if(value>0)
                    j=j<<1;
            }
            cout<<ans<<endl;
        }
        else
            cout<<n<<endl;
    }
    return 0;
}
