#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL arr[30]={0};
int main(){
    ios_base::sync_with_stdio(false);

    LL n,t,temp;
    cin>>t;n=t;

    if(t==1){
        cin>>temp;
        cout<<temp;

        return 0;
    }
    while(t--){
        cin>>temp;

        for(int i=0;i<20;i++){
            if(temp & 1){
                arr[i]++;
            }
            temp/=2;
        }
    }
    LL res=0;
    for(int i=0;i<20;i++){
        res += arr[i]*( n - arr[i] )*(1<<i);
    }

    cout<<res<<endl;

    return 0;
}
