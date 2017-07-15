#include<stdio.h>
#include<stdlib.h>
#define LL long long
#define LOOP(x,y) for(y=0;y<x;y++)
int comp(const void *p,const void *q)
{
    if(*((int*)p)>*((int*)q))
        return 1;
    if(*((int*)p)<*((int*)q))
        return -1;
    return 0;
}
int main()
{
    LL n,j;
    while(scanf("%lld", &n)==1&&n!=0)
    {
        LL arr1[n],arr2[n];
        LOOP(n,j)
        {
        scanf("%lld ", &arr1[j]);
        }
        qsort(arr1,sizeof(arr1)/sizeof(arr1[0]),sizeof(arr1[0]),comp);
        LOOP(n,j)
        {
        scanf("%lld", &arr2[j]);
        }
        qsort(arr2,sizeof(arr1)/sizeof(arr1[0]),sizeof(arr2[0]),comp);
        LL ans=0;
        LOOP(n,j)
        {
        ans+=(arr1[j])*(arr2[n-1-j]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
