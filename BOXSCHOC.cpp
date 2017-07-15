#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;

        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int a,b,k,count=0;
        cout<<"Case 1:"<<endl;
        while(q--){
            cin>>a>>b>>k;

            count=0;
            for(int i=a;i<=b;i++){
                if(!(v[i] % k)){
                    count++;
                }
            }
            cout<<count<<endl;
        }
    }
    return 0;
}
