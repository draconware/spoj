#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *reverse(char *p)
{
    int left=0,right=strlen(p)-2;
    while(right>left)
    {
        char num=*(p+left);
        *(p+left)=*(p+right);
        *(p+right)=num;
        right--;
        left++;
    }
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
          char s[10];
          scanf("%s",s);
          char q[10];
          strcpy(q,s);
          if(strcmp(reverse(q),s)==0)
          printf("yes");
          else
          printf("no");
    }
}
