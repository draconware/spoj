#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        float m,ans=1;
        scanf("%f",&m);
        for(int i=1;i<=m;i++){
            ans*=((m+i)/i);
        }printf("%d\n",(int)ans);
    }
}
