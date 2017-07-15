#include<stdio.h>
#define LL long long
#define LOOP(x) for(i=0;i<x;i++)
#define SCAN(x) scanf("%lld", &x)
#define PRINT(x) printf("%lld\n",x)
void swap(LL *p,LL *q)
{
    LL store=*p;
    *p=*q;
    *q=store;
}
int main()
{

    LL n,k,q,i;
    scanf("%lld %lld %lld", &n, &k, &q);
    LL arr[n];
    LOOP(n)
        SCAN(arr[i]);
    k=k-((k/n)*k);
    if(k>0)
    {
        LOOP(n-k)
            swap(&arr[n-1-k-i],&arr[n-1-i]);
        if(n%2!=0)
            swap(&arr[0],&arr[1]);
    }
    LOOP(q)
    {
        LL m;
        SCAN(m);
        PRINT(arr[m]);
    }
    return 0;
}
