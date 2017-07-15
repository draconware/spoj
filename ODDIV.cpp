#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX1 10000000005
#define MAX2 100005

vector<int> v;
LL prime[MAX2]={0};

void sieve(){
    for(LL i=2;(i*i)<MAX1;i++){
        if(prime[i] == 0){
            for(LL j=(i*i);j<MAX1;j+=i){
                prime[j]++;
            }
        }
    }
}

void copy_primes(){
    for(LL i=2;i<MAX1;i++){
        if(prime[i]==0){
            v.push_back(i);
        }
    }
}
