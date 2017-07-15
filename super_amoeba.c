#include<stdio.h>
#define LL long long
#define M 1000000007

LL inverse(LL a){
    a=a%M;

    LL y,result=1;
    y=M-2;

    while(y>0){
        if(y & 1){
            result=(result*a)%M;
        }
        y=y>>1;
        a=(a*a)%M;
    }
return result;
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        LL a,b,x,y=1,i,j,k;
        scanf("%lld %lld",a,b);

        for(i=0;i<b;i++){
            y*=a;
            y%=M;
        }
        k=inverse(a);
        j=y;

        for(i=0;i<b-1;i++){
            x=(j*k)%M;
            y=y+x;
        }

        printf("%lld %lld\n",x,y);
    }
}
