#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 10050

bitset<MAX> b;
LL arr[MAX];
LL sum[MAX];

void pre(){
    for(int i=0;i<MAX;i++){
        arr[i]=i;b[i]=1;sum[i]=0;
    }

    for(int i=2;i<MAX;i++){
        if(b[i]){
            arr[i]-=1;
            for(int j=(i*2);j<MAX;j+=i){
                b[j]=0;
                arr[j] = arr[j] - arr[j]/i;
            }
        }
    }
    sum[0]=0;
    for(int i=1;i<MAX;i++){
        sum[i]=sum[i-1]+arr[i];
    }
}

int main(){
    pre();

    int n,t;
    cin>>t;

    while(t--){
        cin>>n;

        LL ans;
        ans = sum[n] * sum[n];
        cout<<ans<<endl;
    }
    return 0;
}
