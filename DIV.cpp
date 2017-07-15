#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000000
#define MAX2 1005

vector<LL> prime;
int arr[MAX2]={0};

void sieve(){
    for(LL i=3;(i*i) < MAX2;i+=2){
        if(!(prime[i])){
            for(LL j=(i*i);j<=MAX2;j+=i){
                arr[j]=1;
            }
        }
    }
    prime.push_back(2);
    for(LL i=3;i<MAX2;i+=2){
        if(!(arr[i])){
            prime.push_back(i);
        }
    }
}

bool isprime(int x){
    if(x==1){
        return false;
    }
    for(int k = 2;(k*k)<=x;k++){
        if(!(x%k)){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    LL pos=0;
    for(LL i=4;i<=MAX;i++){
        LL temp=i;
        LL k=0,ans=1,res=1;

        for(LL j=prime[k];(k<prime.size())&&((j*j)<=i);j=prime[++k]){
            while(!(i%j)){
                ans++;
                temp/=j;
            }
        }
        if(temp!=1){
            res*=2;
        }
        k=0,temp=i;
        for(LL t=prime[k];(k<prime.size())&&((t*t)<=i);t=prime[++k]){
            if(!(temp%t)){
                int x = temp/t;
                if(x!=t && isprime(x)){
                    pos++;
                    if(!(pos%9)){
                        cout<<i<<endl;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
