#include<stdio.h>
#define LOOP(x) for(i=0;i<x;i++)
#define SCAN(x) scanf("%lld", &x)
#define L long long
int main()
{
    L n;
    while(1)
    {
        SCAN(n);
        if(n==-1)break;
        L i,arr[n],shift=0;
        L avg=0;
        LOOP(n)
        {
            SCAN(arr[i]);
            avg+=arr[i];
        }
        if(avg%n!=0){printf("-1\n");}
        else
        {avg=avg/n;
        LOOP(n)
        {
            if(arr[i]>avg)
                shift+=(arr[i]-avg);
        }
        printf("%lld\n",shift);
        }
    }return 0;
}
