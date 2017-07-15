#include<stdio.h>
#include<string.h>
#define LOOP(x) for(i=0;i<x;i++)
#define LL long long
int main()
{
    LL n;
    scanf("%lld", &n);
    while(n--)
    {
        LL k;
        scanf("%lld", &k);
        LL x[k],y[k],i,jump=0;
        double m,m1,c,c1;
        LOOP(k)
            scanf("%lld %lld", &x[i], &y[i]);
        m=(y[1]-y[0])/(x[1]-x[0]);
        c=y[0]-m*x[0];
        for(i=1;i<k;i++)
        {
            m1=(y[i+1]-y[i])/(x[i+1]-x[i]);
            c1=y[i]-(m1*x[i]);
            if(m!=m1 || c!=c1)
            {
                jump--;
                m=m1;
                c=c1;
            }
        }
        printf("%lld",jump);
    }
    return 0;
}
