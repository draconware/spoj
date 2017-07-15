#include<stdio.h>
#include<stdlib.h>
void merge(int L1,int R1)
{
    int array[]
}
void merge_sort(int arr[])
{
    int m=l+(n-l)/2;
    int n=sizeof(arr)/sizeof(arr[0]);
    int L[m+1],R[n-m-1];
    int i;
    for(i=l;i<m+1;i++)
        L[i]=arr[i];
    for(i=m+1;i<n;i++)
        R[i-m-1]=arr[i];
    merge_sort(L);
    merge_sort(R);
    merge(L,R);
}
