#include<bits/stdc++.h>
using namespace std;

#define MAX 100000000000
#define LL long long

LL n,m;

int bin_search(LL arr[],LL i,LL t,LL b){
    LL low = i,high = t;
    while(low<=high){
        LL mid = (low+high)/2 ;
        if(arr[mid] < b){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

void min_difference(LL arr[n][m]){

    LL ans=MAX;
    for(LL i=0;i<n;i++){
        sort(arr[i] , arr[i] + m);
    }
    for(LL i=0;i<n;i++){
        for(LL j=0;j<m;j++){
            LL index = bin_search(arr[i],i,m-1,arr[i][j]);
            ans=min(ans,abs(arr[i][index] - arr[i][j]));

            if(index-1 >= 0){
                ans=min(abs(arr[i][index-1] - arr[i][j]),abs(arr[i][index] - arr[i][j]));
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    cin>>n>>m;

    LL arr[n][m];
    for(LL i=0;i<n;i++){
        for(LL j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    min_difference(arr);
}
