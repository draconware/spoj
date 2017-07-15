#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000005
#define SET 1000000

LL arr[MAX]={0};

void sieve(){
    for(LL i=2;(i*i)<MAX;i++){
        if(arr[i]==0){
            for(LL j=(i*i);j<MAX;j+=i){
                LL k=(j/i);
                if(k%i){
                    arr[j]--;
                }else{
                    arr[j]=1000000000;
                }
            }
        }
    }
}

int main(){
    sieve();
    LL c=0;
    for(LL i=6;i<=SET;i++){
        if(arr[i]<0){
            c++;
            if(!(c%108)){
                cout<<i<<endl;
            }
        }
    }

    return 0;
}
