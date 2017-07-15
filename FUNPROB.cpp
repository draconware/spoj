#include<bits/stdc++.h>
using namespace std;

int main(){
    double n,m;

    while(1){
        cin>>n>>m;

        if(n==0 && m==0){
            break;
        }

        double ans=0;
        if(n>m){
            printf("%.6lf\n",ans);
        }else{
            ans = (m-n+1)/(m+1);
            printf("%.6lf\n",ans);
        }
    }
    return 0;
}
