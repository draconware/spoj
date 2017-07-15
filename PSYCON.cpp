#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 3200

bool mark[MAX];
vector<int> prime;

void pre(){
    memset(mark,1,sizeof(mark));
    for(int i=2;(i*i)<MAX;i++){
        if(mark[i]){
            for(int j=(i*i);j<MAX;j+=i){
                mark[j]=false;
            }
        }
    }
    for(int i=2;i<MAX;i++){
        if(mark[i]){
            prime.push_back(i);
        }
    }
}

int main(){
    pre();

    int t;
    scanf("%d", &t);

    while(t--){
        int n,even=0,odd=0;
        scanf("%d", &n);

        for(int i=0;i<prime.size() && prime[i]<n;i++){
            int temp=0,u=prime[i];
            while(n%u == 0){
                n/=u;
                temp++;
            }
            if(temp>0){
                if(temp%2 == 0){
                    even++;
                }else{
                    odd++;
                }
            }
        }
        if(n>1){odd++;}
        if(even>odd){
            printf("Psycho Number\n");
        }else{
            printf("Ordinary Number\n");
        }
    }
    return 0;
}
