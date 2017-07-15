#include<stdio.h>
#define SCAN(x) scanf("%lld", &x)
#define LOOP(x) for(i=0;i<x;i++)
#define LL long long
int comp(const void *p,const void *q)
{
    if(*((LL*)p)>*((LL*)q))
        return 1;
    if(*((LL*)p)<*((LL*)q))
        return -1;
    return 0;
}
int main()
{
    LL t;
    SCAN(t);
    while(t--)
    {
        LL n,k,i,d,e;
        SCAN(n);
        SCAN(k);
        LL arr[n];
        for(i=0;i<n;i++)
            SCAN(arr[i]);
        qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),comp);
        d=arr[k-1]-arr[0];
        for(i=1;i<=n-k;i++)
        {
            e=arr[k-1+i]-arr[i];
            if(e<d)
                d=e;
        }
        printf("%lld\n",d);
    }
    return 0;
}
