#include<stdio.h>
#include<string.h>

int main(){
    //ios_base::sync_with_stdio(false);

    long t;
    scanf("%ld", &t);

    while(t--){
        printf("\n");
        char a[10],b[10],c[10],op1,op2;
        long n1,n2,n3,count=0;
        scanf("%s %c %s %c %s",a, &op1,b, &op2,c);

        if(strstr(a,"machula") == NULL){
            n1=atoi(a);
        }else{
            count=1;
        }
        if(strstr(b,"machula") == NULL){
            n2=atoi(b);
        }else{
            count=2;
        }
        if(strstr(c,"machula") == NULL){
            n3=atoi(c);
        }else{
            count=3;
        }
        if(!count){
            printf("%ld %c %ld %c %ld\n",n1,op1,n2,op2,n3);
            continue;
        }
        if(count==1){
            n1=n3-n2;
            printf("%ld %c %ld %c %ld\n",n1,op1,n2,op2,n3);
            continue;
        }
        if(count==2){
            n2=n3-n1;
            printf("%ld %c %ld %c %ld\n",n1,op1,n2,op2,n3);
            continue;
        }
        if(count==3){
            n3=n1+n2;
            printf("%ld %c %ld %c %ld\n",n1,op1,n2,op2,n3);
        }
    }
    return 0;
}
