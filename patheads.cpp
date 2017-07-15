#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define SET 100000

LL prime[SET]={0};

void sieve(LL b){
    for(LL i=2;i*i<=b;i++){
        if(prime[i]==0){
            for(LL j=i*2;j<=b;j+=i){
                prime[j]--;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    LL n,k=0,t=0;
    cin>>n;
    sieve(n);

    LL arr[n];
    LL brr[n];
    LL amount[n]={0};

    for(LL i=0;i<n;i++){
        cin>>arr[i];
        brr[i]=arr[i];
    }

    sort(brr,brr+n);

    for(LL i=0;i<n;){
        t=0;
        if(brr[i]==1){
            k++;
            i++;
            continue;
        }
        if(i<n-1){
            if(brr[i] == brr[i+1]){
                t++;
                i++;
                continue;
            }
        }
        if(prime[brr[i]] == 0){
            amount[brr[i]] = t+k;
            t=0;
        }else{
            amount[brr[i]] = t+k;
            t=0;
            for(LL j=i-1-t;j>(k-1);j--){
                if(brr[i]%brr[j] == 0){
                    amount[brr[i]]++;
                }
            }
        }
    }
    for(LL i=0;i<n;i++){
        cout<<amount[arr[i]]<<endl;
    }
    return 0;
}
