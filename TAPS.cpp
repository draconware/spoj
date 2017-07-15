#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        LL x,y=0;
        double time;

        for(int i=0;i<n;i++){
            x *= abs( arr[i] );
        }
        for(int i=0;i<n;i++){
            y+=(x/arr[i]);
        }

        time = (double)x/(double)y ;

        printf("%.3lf\n",time);
    }
}
