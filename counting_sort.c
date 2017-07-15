#include<stdio.h>
#include<string.h>
#define RANGE 255
void counting_sort(char arr[])
{
    char output[strlen(arr)];
    int i,count[RANGE+1];
    memset(count,0,sizeof(count));
    for(i=0;i<strlen(arr);i++)
        count[arr[i]]++;
    for(i=0;i<RANGE;i++)
        count[i+1]+=count[i];
    for(i=0;i<strlen(arr);i++)
    {
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(i=0;i<strlen(arr);i++)
        {arr[i]=output[i];
         printf("%c",arr[i]);}
}
int main()
{
    char arr[]="MAYANKAGGARWAL";
    counting_sort(arr);
    return 0;
}
