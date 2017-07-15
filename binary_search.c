#include<stdio.h>
#define LL long long
#define SCAN(x) scanf("%lld", &x)
#define LOOP(x) for(i=0;i<x;i++)
LL binary_search(LL arr[],LL high,LL low,LL target)
{
    while(low<high)
    {
        LL mid=(low+high)/2;
        if(arr[mid]<target)
            low=mid+1;
        else
            high=mid;
    }
    if(arr[low]==target)
        return low;
    else
        return -1;
}
int main()
{
    LL n,q;
    SCAN(n);
    SCAN(q);
    LL arr[n],i,target;
    LOOP(n)
        SCAN(arr[i]);
    LOOP(q)
        {SCAN(target);
        if(target>arr[n-1])
            printf("-1\n");
        else
            printf("%lld\n",binary_search(arr,n-1,0,target));}
        return 0;
}
