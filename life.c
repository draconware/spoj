#include<stdio.h>
int main()
{
    int n;
    while(n>-100||n<100)
    {
        scanf("%d",&n);
        if(n==42)
            break;
        printf("%d\n",n);
    }
}
