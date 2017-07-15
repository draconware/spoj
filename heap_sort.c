#include<stdio.h>
#include<stdlib.h>
void swap(int *p,int *q)
{
    int store=*p;
    *p=*q;
    *q=store;
}
void heaping(int arr[],int n,int i)
{
    int l=i;
    int right=2i+2;
    int left=2i+1;
    if(left< n && arr[l]<arr[left])
        l=left;
    if(right < n && arr[l]<arr[right])
        l=right;
    if(l!=i)
    {
        swap(&arr[i],&arr[l]);
        heaping(arr,n,l);
    }
}
void heap_sort(int arr[],int n)
{
    int i=n/2-1;
    for(;i>=0;i--)
        heaping(arr,n,i);
    for(i=n-1;i>=0;i--)
    {
        swap(&arr[i],&arr[0]);
        heaping(arr,i,0);
    }
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
}
int main()
{
    int arr[]={12,11,13,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr,n);
    return 0;
}
