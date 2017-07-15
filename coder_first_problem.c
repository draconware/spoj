#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long f(int n){
    int i;
    if(n==0 || n==1 || n==2)
        return n;
    if(n==3 || n==5 || n==7)
        return 0;
    long a = (int)floor(sqrt((float)n));
    if(n%a != 0){
        for(i=a-1;i>1;i--){
            if(n%i == 0){
                a=i;
                break;
            }
            if(i==2)
                return 0;
        }
    }
    long b=(n/a);
    return (f(a) + f(b));
}
int main(){
    long x;
    scanf("%ld", &x);
    printf("%ld\n",f(x));
}
