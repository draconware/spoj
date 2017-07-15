#include<stdio.h>
#include<string.h>
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
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
   int n,k,s,i=0,ans=0;
   scanf("%d%d%d", &n, &k, &s);
   int num[n];
   for(;i<n;i++)
    printf("%d",&num[i]);
   bubble_sort(num[],n);
   for(i=0;(ans>=k*s;i++)
     ans+=num[];
   printf("%d",i+1);
}

