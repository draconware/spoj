#include<iostream>
using namespace std;
#define LL long long
int main(){
    LL t;
    cin>>t;
    while(t--){
        LL k,i=192;
        cin>>k;
        i+=(k-1)*250;
        cout<<i<<endl;
    }
    return 0;
}
