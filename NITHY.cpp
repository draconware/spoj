#include<bits/stdc++.h>
using namespace std;

#define S(x) scanf("%d", &x)

int main(){
    int t,n;
    S(t);

    while(t--){
        S(n);

        int x = (n%10);
        if(9*(10-x) <= n){
            printf("%d\n", 10-x );
        }else{
            printf("Impossible\n");
        }
    }
    return 0;
}
