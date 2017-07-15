#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        int ans,flag1=0,flag2=0;
        string arr[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

        int brr[13] = {0,3,3,6,1,4,6,2,5,0,3,5,1};

        if(a==29 && b==2){
            a=28;
            flag1=1;
        }

        if(!(c%4)){
            if(c%100){
                flag2=1;
            }else{
                if(!(c%400)){
                    flag2=1;
                }
            }
        }

        ans = (c-1)%7 + (brr[b-1] + a%7) + (c/4 - c/100 + c/400)%7 ;
        //cout<<ans<<endl;

        if(flag1){
            ans++;
            ans%=7;
            flag2=0;
            //cout<<ans<<endl;
        }

        if(flag2 && b<=2){
            ans--;
            ans = (ans+7)%7;
            //cout<<ans<<endl;
        }
        ans%=7;
        cout<<arr[ans]<<endl;
    }
}
