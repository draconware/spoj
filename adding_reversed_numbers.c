#include<stdio.h>
int reverse(int x)
{
    int ans=0;
    for(;x>0;)
    {
        ans=ans*10+x%10;
        x=x/10;
    }return ans;
}
int main()
{
    int t,m,n,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d", &m, &n);
        m=reverse(m);
        n=reverse(n);
        int sum=m+n;
        sum=reverse(sum);
        printf("%d\n",sum);
    }
}
