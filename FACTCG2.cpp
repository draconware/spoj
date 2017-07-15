#include<bits/stdc++.h>
using namespace std;

#define MAX 10000009

int a[MAX]={0};

void sieve(){
    for(int i=2;(i*i)<MAX;i++){
        if(!(a[i])){
            for(int j=(i*i);j<MAX;j+=i){
                if(!a[j]){
                    a[j]=i;
                }
            }
        }
    }
}

int main(){
    sieve();
    int n;
    while(scanf("%d", &n)!=EOF){
        if(n==1){
            printf("1");
        }else{
            printf("1");

            if(a[n] == 0){
                printf(" x %d",n);
            }else{
                while(1){
                    printf(" x %d",a[n]);
                    n /= a[n];
                    if(a[n]==0){
                        break;
                    }
                }
                printf(" x %d",n);
            }
        }
        printf("\n");
    }
    return 0;
}
