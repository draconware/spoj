#include<stdio.h>
#include<stdlib.h>
void insert_sort(int arr[],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        int store=arr[i];
        for(j=i-1;j>=0&&arr[j]>arr[i];j--)
            arr[j+1]=arr[j];
        arr[j+1]=store;
    }
}
int main()
{
    int arr[]={1,3,2,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    insert_sort(arr,n);
    int i=0;
    for(;i<n;i++)
        printf("%d ",arr[i]);
}
