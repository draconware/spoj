#include<stdio.h>
#include<stdlib.h>
void swap(int *p,int *q)
{
    int store=*p;
    *p=*q;
    *q=store;
}
int junction(int arr[],int low,int high)
{
    int i,j;
    i=low-1;//declaration of small numbers then junction number//
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<=arr[high])
        {
            i++;
            swap(&arr[i],&arr[j]);//change of larger with smaller if j>i//
        }
        swap(&arr[i+1],&arr[high]);//putting junction element between the numbers more than it(right) and smaller than it(left)//
    }
    return (i+1);//junction element position//
}
void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {int junc=junction(arr,low,high);

    quick_sort(arr,low,junc-1);
    quick_sort(arr,junc+1,high);
}}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[]={1,3,2,9,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,n-1);
    print(arr,n);
    return 0;
}
