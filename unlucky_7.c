#include<stdio.h>
#define LL long long
int main(){
    int t,j;
    scanf("%d", &t);
    for(j=1;j<=t;j++){
        LL n,n1,n2,ans=0,i;

        scanf("%lld", &n);

        n1=(n/7);

        n2=(n/13);

        ans+=((7*((n1*(n1+1))/2)) + (13*((n2*(n2+1))/2)));

        if(n%7 == 0 || n%13 == 0){
            ans-=n;
        }


        if(n/91 != 0){
            for(i=1;i<=(n/91);i++){
                ans-=(91*i);
            }
        }

        printf("Case %d: %lld\n",j,ans);
    }

    return 0;
}

