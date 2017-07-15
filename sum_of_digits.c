#include<stdio.h>
#include<string.h>
#define LOOP(x) for(i=0;i<x;i++)
int main()
{
    int t;
    char arr[60];
    scanf("%d", &t);
    while(t--)
    {
        int ans=0;
        scanf("%s",arr);
        int i,n=strlen(arr);
        LOOP(n)
            ans+=(arr[n-1-i]-'0');
        printf("%d\n",ans);
    }
    return 0;
}
