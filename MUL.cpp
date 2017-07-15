#include<bits/stdc++.h>
using namespace std;

void fast_multiply(LL num1[],LL num2[]){
    LL temp,carry;
    for(LL i=0;i<)

}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    scanf("%d", &t);

    while(t--){
        string num1,num2;
        scanf("%s %s",num1,num2);

        LL _num1[num1.length()];
        LL _num2[num2.length()];

        for(LL i=0;i<num1.length();i++){
            _num1[i]=(num1%10)-'0';
        }
        for(LL i=0;i<num2.length();i++){
            _num2[i]=(num2%10)-'0';
        }

        if(num1.length()>num2.length()){
            fast_multiply(_num1,_num2,num1.length());
        }else{
            fast_multply(_num2,_num1,num2.length());
        }
    }
    return 0;
}
