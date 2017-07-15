#include<bits/stdc++.h>
using namespace std;

#define LL long long

int arr[1000][1000];

int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0){return 0;}
        long long a=0,b=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                a+=arr[i][j];
            }
        }
        long long pos=0,neg=0,x=0,y=0;
        for(int i=0;i<n;i++){
            x=0,y=0;
            for(int j=1;j<n;j++){
                x+=arr[i][j];
            }
            for(int j=1;j<n;j++){
                y+=arr[j][i];
            }
            cout<<(x+y)<<endl;
            if(x+y < 0){
                neg+=(x+y);
            }else{
                pos+=(x+y);
            }
        }
        cout<<a<<" "<<pos<<endl;
    }
    return 0;
}
