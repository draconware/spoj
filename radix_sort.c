#include<stdio.h>
#include<stdlib.h>
int max(int arr[],int n)
{
    int i,p=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>p)
            p=arr[i];
    }return p;

}
void counting_sort(int arr[],int n,int exp)
{
    int output[n];
    int i,count[10]={0};
    for(i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;
    for(i=0;i<10;i++)
        count[i+1]+=count[i];
    for(i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        arr[i]=output[i];
}
void radix_sort(int arr[],int n)
{
    int exp;
    int m=max(arr,n);
    for(exp=1;m/exp>0;exp*=10)
    counting_sort(arr,n,exp);
    for(exp=0;exp<n;exp++)
        printf("%d ",arr[exp]);
}
int main()
{
    int arr[]={23,54,123,4,2,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr,n);
}
