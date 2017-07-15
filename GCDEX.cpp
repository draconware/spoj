#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000001

LL res[MAX];
LL phi[MAX];

void pre(){
    memset(res,0,sizeof(res));
    memset(phi,0,sizeof(phi));

    for(LL i=2;i<MAX;i++){
        if(phi[i]==0){
            phi[i]=(i-1);
            for(LL j=2*i;j<MAX;j+=i){
                if(phi[j]==0){phi[j]=j;}
                phi[j] -= (phi[j]/i);
            }
        }
    }

    for(LL i=1;i<MAX;i++){
        for(LL j=2;j*i<MAX;j++){
            res[i*j] += i*(phi[j]);
        }
    }

    for(LL i=2;i<MAX;i++){
        res[i]+=res[i-1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();
    LL n;
    while(1){
        cin>>n;
        if(n==0){return 0;}
        cout<<res[n]<<endl;
    }
}
