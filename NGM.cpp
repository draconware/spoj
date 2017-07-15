#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    LL n;
    cin>>n;

    if(!(n%10)){
        cout<<"2"<<endl;
    }else{
        cout<<"1\n"<<n%10<<endl;
    }
    return 0;
}
