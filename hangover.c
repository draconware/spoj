#include<stdio.h>
int main(){
    while(1){
        float c;
        scanf("%f", &c);
        if(c == 0.00)
            break;
        long long i;
        for(i=2;c >= 0.00;i++){
            c-=(1.00/(float)i);
        }
        printf("%lld card(s)\n",i-2);
    }
    return 0;
}
