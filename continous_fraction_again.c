#include<stdio.h>
#include<string.h>
#define LL long long
int main()
{
    while(1)
    {
        LL n,m,i,j,p,q,t=1,temp;
        scanf("%lld %lld", &n, &m);
        printf("%d %d\n",n,m);
        if(m==0 && n==0)
            return 0;
        char arr[n][m];
        for(i=0;i<n;i++)
        {
            scanf("%[^\n]s",&arr[i]);
        }
        for(i=0;i<n;i++)
        {
            printf("%s",arr[i]);
        }
        for(j=m-1;j>=0;j++)
        {
            if(arr[n-1][j]>=48)
            {
                q=arr[n-1][j];
                p=1;
                printf("%lld %lld\n",q,p);
                break;
            }
        }
        if(n==1)
            printf("%d %d\n",q,p);
        else
        {
            for(i=n-2;i>=0;i-=2)
            {
                for(j=m-1;j>=0;j--)
                {
                    if(arr[i][j]>=48)
                    {
                        t=arr[i][j]-'0';
                        p+=(t*q);
                        printf("%lld %lld %lld\n",t,p,q);
                    }
                    if(i>=1)
                    {
                        temp=q;
                        q=p;
                        p=temp;
                        printf("%lld %lld\n",p,q);
                        break;
                    }
                }
            }
        }
        printf("%lld %lld",p,q);
    }
    return 0;
}
