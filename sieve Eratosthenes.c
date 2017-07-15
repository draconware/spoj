#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n=10,prime[n],j=0;
    for(;j<n+1;j++)
    {prime[j]=0;}
    j=2;
    while(j<=(int)sqrt((float)n))
          {int k=j;
              if(prime[j]==0)
            {
               while(k*j<=n)
               {
                   prime[k*j]=1;
                   k++;
               }
            }
          j++;
          }for(j=2;j<=n;j++)
          {
              if(prime[j]==0)
                printf("%d\n",j);
          }
    return 0;
}
