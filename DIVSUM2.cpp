#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long
#define MAX 100000009

bitset<MAX> b;
vector<LL> prime;

void pre(){
    b.flip();
    for(LL i=4;i<MAX;i+=2){
        b[i]=false;
    }
    for(LL i=3;(i*i)<MAX;i+=2){
        if(b[i]){
            for(LL j=(i*i);j<MAX;j+=i){
                b[j]=false;
            }
        }
    }prime.push_back(2);
    for(LL i=3;i<MAX;i+=2){
        if(b[i]){
            prime.push_back(i);
        }
    }
}

int main(){
    pre();

    LL t;
    scanf("%llu", &t);

    while(t--){
        LL n,m,ans=1;
        scanf("%llu", &n);m=n;

        for(LL i=0;i<prime.size() && prime[i]<n;i++){
            LL temp=1,k=prime[i],u=prime[i];
            while(n%u == 0){
                temp+=(k);
                k*=u;
                n/=u;
            }
            ans*=temp;
            //cout<<"for--- "<<u<<"------ "<<temp<<endl;
        }
        if(n>1){ans*=(1+n);}
        printf("%llu\n",ans-m);
    }
    return 0;
}
