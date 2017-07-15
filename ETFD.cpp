#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000000

LL phi[MAX]={0};

LL euler(LL i){
    LL k=i;
    double res=i;
    for(LL j=2;(j*j)<=i;j++){
        if(k%j == 0){
            res*=(1.0-(1.0/(double)j));
            while(!(k%j)){
                k/=j;
            }
        }
    }
    return (LL)res;
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;
    while(t--){
        LL m,n,k;
        cin>>m>>n>>k;

        LL ans[n],value=0;
        memset(ans,0,sizeof(ans));
        bool mark[n];

        for(LL i=n;i>=m;i--){
            LL c=i,count=0;
            for(;c!=1;){
                count++;
                c=euler(c);
            }
            if(count==k){
                value++;
            }
        }
    }
    return 0;
}
