#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 10005

LL arr[MAX]={0};

void sieve(){
    for(LL i=2;(i*i) < MAX;i++){
        if(arr[i] == 0){
            for(LL j=(i*i);j < MAX;j+=i){
                arr[j]++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    sieve();

    vector<LL> prime;

    for(LL i=2;i < MAX;i++){
        if(arr[i] == 0){
            prime.push_back(i);
        }
    }

    while(t--){
        LL n;
        cin>>n;
        LL arr[n];

        for(LL i=0;i<n;i++){
            cin>>arr[i];
        }
        LL mini=MAX;
        for(LL i=0 ;(i<prime.size())&&(i<arr[n-1]) ; i++){
            LL ans=0;
            for(LL j=0 ; j < n ; j++){
                if(!(arr[j]%prime[i])){
                    continue;
                }
                ans += ((((arr[j]/prime[i])+1)*prime[i])-arr[j]);
            }
            if(mini > ans){
                mini = ans;
            }
        }
        cout<<mini<<endl;
    }
    return 0;
}
