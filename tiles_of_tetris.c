#include<stdio.h>
int gcd(long long  int m,long long  int n)
{
    if(m==n)
        return m;
    if(m>n)
        return gcd(m-n,n);
    return gcd(m,n-m);
}
long long int lcm(long long  int m,long long  int n)
{
    long long int t=(m*n)/gcd(m,n);
    return t;
}
int main()
{
    long long  int i,m,n;
    for(i=0;1;i++)
    {
        scanf("%lld %lld", &m, &n);
        if(m==0&&n==0)
            return 0;
        else
            printf("%lld\n", lcm(m,n)/gcd(m,n));
    }return 0;
}
