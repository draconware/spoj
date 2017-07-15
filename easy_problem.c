#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n=137,i,arr[15],j;
    for(i=16384,j=0;i>0;i/=2,j++)
    {
        if(n/i!=0)
            {printf("1");
            arr[j]=1;}
        else
            {printf("0");
             arr[j]=0;}
        n=n%i;
    }

    return 0;
}
