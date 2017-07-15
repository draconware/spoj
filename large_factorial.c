#include<stdio.h>
#define LL long long
#define SCAN(x) scanf("%lld", &x)
#define PRINT(x) printf("%lld",x)
#define T 158
LL i,j=0;
void factorial(LL arr[],LL j,LL x)
{
    LL carry=0;
    for(i=0;i<j;i++)
    {
        LL temp = arr[i];
        arr[i]=((arr[i]*(x))+carry)%10;
        carry=(((temp*x)+carry)/10);
    }
    arr[i]=carry;
}
int main()
{
    LL n,arr[T],k,x;
    SCAN(n);
    int m=n;
    while(m>0)
    {
        arr[j]=m%10;
        m/=10;
        j++;
    }

    for(x=n-1;x>1;x--)
        factorial(arr,j,x);
    LL a=0;
    for(k=i;k>=0;k--)
    {
        if(arr[k]==0)
            {i--;
            continue;}
        break;
    }
    for(a=i;a>=0;a--)
        printf("%lld",arr[a]);
    return 0;
}
