#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n==1){
            cout<<"10"<<endl;
        }else{
            cout<<"9";

            n--;
            while(n--){
                cout<<"0";
            }
            cout<<endl;
        }
    }
    return 0;
}
