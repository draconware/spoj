#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LOOP(x) for(i=0;i<x;i++)
int comp(const void *p,const void *q)
{
    if(*((int*)p)>*((int*)q))
        return 1;
    if(*((int*)p)<*((int*)q))
        return -1;
    return 0;
}
int main()
{
    int i,arr1[26];
    LOOP(26)
         scanf("%d", &arr1[i]);
    char arr2[10];
    scanf("%s", &arr2);
    int w=strlen(arr2);
    int arr3[w];
    LOOP(w)
        arr3[i]=arr1[(int)arr1[i]-97];
    qsort(arr3,sizeof(arr3)/sizeof(arr3[0]),sizeof(arr3[0]),comp);
    printf("%d",(arr3[w-1]*w));
}
