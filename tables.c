#include<stdio.h>
#include<stdlib.h>
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
    int n,k,s,key=0;
    scanf("%d%d%d", &n, &k, &s);
    int arr[n],i=0;
    for(;i<n;i++)
        scanf("%d", &arr[i]);
    qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),comp);
    for(i=n-1;i>=0;i--)
    {
        key+=arr[i];
        if(key>=k*s)
        {printf("%d ", n-i);
         break;}
    }
}
