#include<stdio.h>
#include<stdlib.h>
#define LL long long
#define LOOP(x) for(i=0;i<x;i++)
#define SCAN(x) scanf("%lld", &x)
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
    LL t;
    SCAN(t);
    while(t>0)
    {
        LL n,i;
        SCAN(n);
        LL arr[n],arr1[n],aRR[n],aRR1[n];
        LOOP(n)
        {
            SCAN(arr[i]);
            arr1[i]=arr[i];
            SCAN(aRR[i]);
            aRR1[i]=aRR[i];
        }
        qsort(arr1,sizeof(arr1)/sizeof(arr1[0]),sizeof(arr1[0]),comp);
        qsort(aRR1,sizeof(aRR1)/sizeof(aRR1[0]),sizeof(aRR1[0]),comp);
        if(arr1[n-1]>aRR1[0])
            i=0;
        else
            break;
        LL j;
        for(j=0;j<n;j++)
        {
            if(arr[j]==arr1[n-1-i])
            {
                printf("%lld\n",j+1);
                break;
            }
        }
        t--;
    }
    return 0;
}
