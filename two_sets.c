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
int gcd_(int a,int b)
{
    if(b%a==0)
        return a;
    gcd_(b%a,a);
}
int main()
{
    int m,n,ans=1,i,count=0;
    scanf("%d %d",&n,&m);
    int l[m],g[n];
    for(i=0;i<n;i++)
        scanf("%d",&l[i]);
    qsort(l,sizeof(l)/sizeof(l[0]),sizeof(l[0]),comp);
    for(i=0;i<m;i++)
        ans=ans*l[i];
    for(i=0;i<m;i++)
        l[i+1]=gcd_(l[i],l[i+1]);
    int lcm=(ans/l[i+1]);
    for(i=0;i<n;i++)
        scanf("%d",&cd[i]);
    qsort(g,sizeof(g)/sizeof(g[0]),sizeof(g[0]),comp);
    for(ans=1,i=0;i<n;i++)
        g[i+1]=gcd_(g[i],g[i+1]);
    for(i=lcm;i<=gcd;i=i>>1)
        count++;
    printf("%d",count);
    return 0;
}
