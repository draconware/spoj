#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define LOOP(x) for(LL i=0;i<x;i++)
#define LIM 10000000000

int main(){
    ios_base::sync_with_stdio(false);

    LL n,m;
    cin>>n>>m;

    LL arr[n];
    LOOP(n){
        cin>>arr[i];
    }
    LL maxi=0,mini=0;

    LOOP(n){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }

    LL target;
    while(mini<=maxi){
        LL amount=0,mid=(maxi+mini)/2;

        LOOP(n){
            if(arr[i]>=mid){
                amount+=(arr[i]-mid);
            }
        }
        if(amount==m){
            target=mid;
            break;
        }
        if(amount>m){
            target=mid;
            mini=mid+1;
        }
        if(amount<m){
            maxi=mid-1;
        }
    }
    cout<<target<<endl;
}
