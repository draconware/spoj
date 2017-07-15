#include<bits/stdc++.h>
using namespace std;

long long count_zero(int x){
    int total=0;

    while(x){
        if(x%10 == 0){
            total++;
        }
        x/=10;
    }
    return total;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,flag1=0,flag2=0;
        long long total=0;
        cin>>a>>b;

        for(int i=a;i<=b;i++){
            total+=(count_zero(i));
        }

        cout<<total<<endl;
    }
    return 0;
}

