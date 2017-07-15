#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 10000009

bool mark[MAX];
vector<LL> prime;

void pre(){
    memset(mark,1,sizeof(mark));
    for(LL i=2;(i*i)<MAX;i++){
        if(mark[i]){
            for(LL j=(i*i);j<MAX;j+=i){
                mark[j]=false;
            }
        }
    }
    for(LL i=2;i<MAX;i++){
        if(mark[i]){
            prime.push_back(i);
        }
    }
}

int main(){
    pre();
    int t;
    cin>>t;

    while(t--){
        LL n,ans=0,k;
        cin>>n;

        for(LL i=1;i<=n;i++){
            ans++;k=i;
            for(LL j=0;j<prime.size() && (prime[j]*prime[j])<=k;j++){
                int e=0;
                while(k%(prime[j]) == 0){
                    e++;
                    k/=prime[j];
                }
                if(e>1){ans--;break;}
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
