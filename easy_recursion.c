#include<stdio.h>
#define LL unsigned long long
int f(int x){
    if(x==1)
        return 1;
    if(x==2)
        return 3;
    if(x==3)
        return 2;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        LL m,n;
        int ans;
        scanf("%lld", &m);
        if(m==1){
            ans=f(m);
            printf("%d\n",ans);
            continue;
        }
        n=m-1;
        if(n>3){
            if(n%3 == 0){
                if((n/3)%2 == 0)
                    ans=3-f(3);
                else
                    ans=3+f(3);
            }
            else if((n/3)%2 != 0)
                ans=3-f(n%3);
            else
                ans=3+f(n%3);
        }
        if(n<=3){
            ans=3+f(n);
        }
        printf("%d\n",ans);
    }
    return 0;
}
