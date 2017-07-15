#include<stdio.h>
int main()
{
    int i,m;
    long long int t,n;
    scanf("%lld", &t);
    for(i=0;i<t;i++)
    {
        scanf("%lld", &n);
        int j=1;
        if(n%11 <= 3)
            m=3*(n%11);
        if(n%11>=4 && n%11<=7)
            m=11*((n%11)-1)-8*(n%11);
        if(n%11>=8)
            m=11*((n%11)-2)-8*(n%11);
        printf("%d\n",m);
    }

}
