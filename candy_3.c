#include<stdio.h>
#define LL unsigned long long
#define SCAN(x) scanf("%lld", &x)
int main()
{
    LL test;
    SCAN(test);
    while(test--)
    {
        printf("\n");
        LL n,i,ans=0;
        SCAN(n);
        LL arr[n];
        for(i=0;i<n;i++)
        {
            SCAN(arr[i]);
            ans+=arr[i];
            ans%=n;
        }
        if(ans%n==0)
            printf("YES\n");
        else
            printf("NO");
    }
    return 0;
}
