#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{   int t,m,n,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {scanf("%d%d", &m, &n);
    if(m==1)
        m++;
    int prime[n+1],j=0;
    for(;j<n+1;j++)
    {prime[j]=0;}
    j=2;
    while(j<=(int)sqrt((float)n))
          {int k=j;
              if(prime[j]==0)
            {
               while(k*j<=n+1)
               {
                   prime[k*j]=1;
                   k++;
               }
            }
          j++;
          }for(j=m;j<=n+1;j++)
          {
              if(prime[j]==0)
                printf("%d\n",j);
          }

}}

