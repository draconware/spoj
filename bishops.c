#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char arr[110];
    int brr[110];
    while(scanf("%s",arr)!=EOF)
    {
        if(strlen(arr)==1&&arr[0]==49)
        {
            printf("1\n");
            continue;
        }
        int temp,j,k,c,i,carry=0,n=strlen(arr);
        for(i=0;i<n;i++)
            brr[i]=arr[n-1-i]-'0';
        for(i=0;i<n;i++)
        {
            temp=brr[i];
            brr[i]=(brr[i]*2+carry)%10;
            carry=(temp*2+carry)/10;
        }
        if(carry>0)
            {brr[i]=carry;
             k=i; }
        else
            k=i-1;
        c=2;
        for(j=0;j<=k;j++)
        {
            if(brr[j]>=c)
                {brr[j]=brr[j]-c;
                 break;}
            else
            {
                brr[j]=10+brr[j]-c;
                c=1;
            }
        }
        if(brr[k]>0)
            printf("%d",brr[k]);
        for(i=k-1;i>=0;i--)
        {
            printf("%d",brr[i]);
        }
        printf("\n");
    }
    return 0;
}
