#include<stdio.h>
#include<math.h>
int main()
{
    long int n=1,i,m;
    m=n;
    for(i=2;i<=floor(sqrt(n));)//declared i limit less than square root of n//
    {
        if(m%i==0)             //getting some factors of number//
        {printf("%d ",i);
         m/=i;
         continue;
         }
         i++;
    }if(m>1)
    {
        printf("%d",m);
    }
}
