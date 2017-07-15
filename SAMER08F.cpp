#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0){
            return 0;
        }

        int ans = (n*(n+1)*((2*n)+1))/6;

        cout<<ans<<endl;
    }
}
