#include<stdio.h>
#include<string.h>
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
void print(int arr[],int x)
{
    int i=0;
    for(;i<x;i++)
        printf("%d",arr[i]);
}
void bubble_sort(int arr2[],int x)
{
    int i=0,c=0;
    for(;i<x-1;i++)
    {
        if(arr2[i]>arr2[i+1])
        {
            swap(&arr2[i],&arr2[i+1]);
            c++;
        }
        if(c>0&&i==x-2)
            {i=-1;
            c=0;}
    }
}
int main()
{
    int num[]={5,4,3,2,1};
    int n=sizeof(num)/sizeof(num[0]);
    bubble_sort(num,n);
    print(num,n);
    return 0;
}
