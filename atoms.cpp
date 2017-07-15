#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int p;
    cin>>p;
    while(p--){
        unsigned long long int n,k,m,time=0;
        cin>>n,k,m;
        if(k<=m/n){
            time++;
            n=n*k;
            while(k<=m/n){
            n=n*k;
            time++;
            }
        }
        cout<<time<<endl;
    }
    return 0;
}
