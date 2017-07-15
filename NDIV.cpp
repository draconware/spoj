#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<int> prime;
bool mark[32000]={0};

void sieve(){
    for(int i=3;i<=180;i+=2){
        if(!mark[i]){
            for(int j=(i*i);j<=32000;j+=i){
                mark[j]=1;
            }
        }
    }

    prime.push_back(2);
    for(int i=3;i<=32000;i+=2){
        if(!mark[i]){
            prime.push_back(i);
        }
    }
}

int main(){
    sieve();

    int a,b,n,amount=0;
    scanf("%d %d %d", &a, &b, &n);

    for(int i=a;i<=b;i++){
        int res=1,c=i,k=0;

        for(int j=prime[k];(j*j)<=c;j=prime[++k]){
            int count=0;
            while(!(c%j)){
                count++;
                c/=j;
            }
            res *= count+1;
        }
        if(c>1){
            res*=2;
        }

        if(res == n){
            amount++;
        }
    }

    printf("%d\n",amount);

    return 0;
}
