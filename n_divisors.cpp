#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define SET 1000000000

LL prime[SET],result=0,use[SET];

void prime_generator(LL a){
    LL k=0;
    memset(prime,0,sizeof(prime));
    for(LL i=2;i*i<=a;i++){
        if(prime[i] == 0){
            result++;
            use[k]=i;
            k++;
            for(LL j=i*2;j<=a;j+=i){
                prime[j]=1;
            }
        }
    }
}

int main(){
    LL a,b,n,ans=1,e=1,show=0;
    cin>>a>>b>>n;

    prime_generator(a);

    if(n==1){
        printf("1/n");
    }else if(n==2){
        printf("%lld\n",result);
    }else{
        for(LL i=a;i<=b;){
            if(prime[i]==0){
                i++;
                continue;
            }else{
                LL j=i;
                for(LL k=2;k<=j;k++){
                    if(a%k == 0){
                        while(j%k == 0){
                            j/=2;
                            e++;
                        }
                        ans*=e;
                    }
                    if(ans>=n && j>1){
                        ans=1;
                        e=1;
                        break;
                    }
                    if(j==1 && ans==n){
                        ans=1;
                        e=1;
                        show++;
                    }
                }
            }
            i++;
        }
        cout<<show<<endl;
    }
    return 0;
}

