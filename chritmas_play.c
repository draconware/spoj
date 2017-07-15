#include<stdio.h>
#include<stdlib.h>
#define SCAN(x) scanf("%lld", &x)
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
   LL t,i;
   SCAN(t);
   LOOP(t,i)
   {
        LL n,k,j,flag=0;
        SCAN(n);
        SCAN(k);
        LL arr[n];
        LOOP(n,j)
            SCAN(arr[j]);
        qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),comp);
        LOOP(n-k+1,j)
        {
            if(arr[j]==arr[k-1+j])
            {
                printf("0\n");
                flag=1;
                break;
            }
        }

   }

}
