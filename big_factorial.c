#include<stdio.h>
#include<string.h>
void factorial(int brr[],int x,int n){
    int i,carry=0;
    for(i=0;i<n;i++){
        int temp=brr[i];
        brr[i]=((brr[i]*x)%10 + carry);
        carry=(temp*x)/10;
    }
    if(carry>0)
        brr[n]=carry;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char arr[3];
        int n,i,brr[160];
        scanf("%s", arr);
        printf("%s\n",arr);
        n=strlen(arr);
        printf("%d\n",n);
        for(i=n-1;i>=0;i--)
            brr[i]=arr[n-1-i]-'0';
            printf("%d ",brr[i]);
        for(i=n-1;i>1;i--){
            factorial(brr,i,n);
            for(i=n-1;i>=0;i--)
                printf("%d ",brr[i]);
            n=sizeof(brr)/sizeof(brr[0]);
            printf("\n%d\n",n);
        }
        for(i=n;i>=0;i--)
            printf("%d",brr[i]);
        printf("\n");
    }
    return 0;
}
