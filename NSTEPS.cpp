#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        LL x,y;
        cin>>x>>y;
        int flag=0;
        if(x==y){
            LL count=0;
            for(LL i=0;i<x;i++){
                if(i%2){
                    count+=3;
                }else{
                    count++;
                }
            }
            cout<<count<<endl;
            flag=1;
        }
        if((x-y)==2){
            LL count=2;
            for(LL i=2;i<x;i++){
                if(i%2){
                    count+=3;
                }else{
                    count++;
                }
            }
            cout<<count<<endl;
            flag=1;
        }
        if(!flag){
            cout<<"No Number"<<endl;
        }
    }
    return 0;
}
