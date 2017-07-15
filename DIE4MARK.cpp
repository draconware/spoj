#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        double a,b;
        cin>>a>>b;

        double ans = ((a-b)/95.0)*100.0 ;
        double temp = floor(ans);

        if(ans - temp >= 0.500000){
            ans = ceil(ans);
        }else{
            ans = floor(ans);
        }

        if(ans > a){
            cout<<"profit"<<endl;
        }else if(ans < a){
            cout<<"loss"<<endl;
        }else{
            cout<<"same"<<endl;
        }
    }
    return 0;
}
