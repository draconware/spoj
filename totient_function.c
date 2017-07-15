#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    scanf("%d", &n);
    float ans=n;
    for(i=2;i*i<=n;i++)
    {
       if(n%i==0)
       {
           while(n%i==0)
           {
               ans*=(1.0-(1.0/(float)i));
               n/=i;
           }
       }
    }
    if(n>1)
        ans*=(1.0-(1.0/(float)n));
    printf("%d",(int)ans);
}
