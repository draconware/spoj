#include<stdio.h>
#include<string.h>
#define LL long long
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL m,n,i,j;
        scanf("%lld %lld", &m, &n);
        LL prime[n-m+1];
        memset(prime,0,sizeof(prime));
        for(i=2;i*i<=n;i++)
        {
            for(j=max(i*i,(m+i-1)/(i*i));j<=n;j+=i)
                prime[j-m]=1;
        }
        for(i=max(2,m);i<=n;i++)
        {
            if(prime[i]==0)
                printf("%lld\n",i);
        }
    }
    return 0;
}
