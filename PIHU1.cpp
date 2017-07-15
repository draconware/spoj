#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        int n,flag=0;
        cin>>n;

        LL p,temp;
        LL v[n];
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v,v+n);
        cin>>p;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                temp = v[j] + v[i];
                if(binary_search( v+j+1 , v+n , p-temp )){
                    flag=1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
