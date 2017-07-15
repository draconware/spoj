#include<stdio.h>
int ternary_search(int l,int h,int x,int arr[])
{
    while(h>=l)
{
    int mid1=l+((h-l)/3);
    int mid2=h-((h-l)/3);
    if(arr[mid1]==x)
        return mid1;
    if(arr[mid2]==x)
        return mid2;
    if(arr[mid1]>x)
        return ternary_search(l,mid1-1,x,arr);
    else if(arr[mid2]<x)
        return ternary_search(mid2+1,h,x,arr);
    else
        return ternary_search(mid1+1,mid2-1,x,arr);
}
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11};
    int n=ternary_search(0,10,3,arr);
    printf("%d",n);
}
