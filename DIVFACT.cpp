#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 50001
#define M 1000000007

LL prime[MAX]={0};
void sieve(){
    for(LL i=2;(i*i)<MAX;i++){
        if(prime[i]==0){
            for(LL j=(i*i);j<=MAX;j++){
                prime[j]--;
            }
        }
    }
}

LL sum_factorial(LL n,vector<LL>& v){
    LL k,c,result=1,ans=1;
    for(LL i=0;i<=v.size();i++){
        k=n; c=v[i]; ans=1;
        if(n < v[i]){
            break;
        }
        while(k>0){
            ans+=((k/c)%M);

            k/=c;
            c=c*v[i];
        }
        result*=ans;
        result%=M;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;
    sieve();
    vector<LL> v;
    for(LL i=2;i<=MAX;i++){
        if(prime[i]==0){
            v.push_back(i);
        }
    }
    for(LL i=0;i<4;i++){
        cout<<v[i]<<" ";
    }
    while(t--){
        LL n;
        cin>>n;
        if(n<=1){
            cout<<"1"<<endl;
            continue;
        }
        cout<<sum_factorial(n,v)<<endl;
    }
    return 0;
}
