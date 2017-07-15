#include<stdio.h>
int main()
{
    int n=25,m=n,result=m,i;
    for(i=2;i*i<=m;)
    {
        if(n%i==0)
           {n/=i;
           continue;}
        result-=result/i;
        i++;
    }if(n>1)
    result-=result/n;
    printf("%d",result);
}
