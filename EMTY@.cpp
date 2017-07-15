#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int t,j=1;
    cin>>t;

    while(j<=t){
        string str;
        stack<char> zero;
        cin>>str;
        int flag=1,n=str.length();

        for(int i=0;i<n;i++){
            if(str[i]=='1'){
                flag=0;
                break;
            }
        }
        if(flag){
            printf("Case %d: no\n",j);
            flag=0;
        }else{
            flag=1;
        }

        for(int i=n-1;i>=0;i--){
            if(str[i]=='0'){
                zero.push(str[i]);
            }
            if(str[i]=='1'){
                if((zero.empty())||(zero.size() < 2)){
                    printf("Case %d: no\n",j);
                    flag=0;
                    break;
                }
                if(zero.size() >= 2){
                    zero.pop();
                    zero.pop();
                }
            }
        }
        if(!zero.empty()){
            printf("Case %d: no\n",j);
            flag=0;
        }
        if(flag){
            printf("Case %d: yes\n",j);
        }
        j++;
    }
    return 0;
}
