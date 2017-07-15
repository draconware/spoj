#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        long long amount=0;
        cin>>n>>k;

        string str;
        cin>>str;

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j<n;j++){
                if(str[j]=='1'){
                    count++;
                }
                if(count==k){
                    amount++;
                }else if(count>k){
                    break;
                }
            }
        }
        cout<<amount<<endl;
    }
    return 0;
}
