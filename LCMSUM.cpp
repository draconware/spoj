#include<bits/stdc++.h>
using namespace std;

#define MAX 1000010

long long arr[MAX];
long long res[MAX]={0};

void pre(){
    for(long long i=1;i<MAX;i++){
        arr[i] = i;
    }

    for(long long i=2;i<MAX;i++){
        if(arr[i] == i){
            for(long long j=i;j<MAX;j+=i){
                arr[j]-=(arr[j] / i);
            }
        }
    }

    for(long long i=1;i<MAX;i++){
        for(long long j=i;j<MAX;j+=i){
            res[j] += (arr[i] * i);
        }
    }
}

int main(){
    pre();

    long long t;
    scanf("%lld", &t);

    while(t--){
        long long n;
        scanf("%lld", &n);

        long long ans = (res[n] + 1)*n;
        ans/=2;

        printf("%lld\n",ans);
    }
    return 0;
}
