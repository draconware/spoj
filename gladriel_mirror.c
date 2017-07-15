#include<stdio.h>
#include<string.h>
void mirror(char *p,int n)
{
    int i=0,j=n-1,flag=1;
    for(;i<j;i++,j--)
    {
        if(*(p+i)!=*(p+j))
        {
            flag=0;
            printf("NO\n");
            break;
        }
    }
    if(flag==1)
        printf("YES\n");
}
int main()
{
    int i,t;
    char arr[80];
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        scanf("%s", arr);
        int n=strlen(arr);
        char s[n+1];
        strncpy(s,arr,n+1);
        mirror(s,n);
    }
    return 0;
}
