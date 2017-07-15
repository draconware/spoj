#include<bits/stdc++.h>
using namespace std;

int main(){
    int b[4];
    for(int i=0;i<4;i++){
        b[i] = 0;
    }

    int out=0,balls=0,i=1,j=2,k=3;
    char x;

    while((out != 2)&&(balls < 6)){
        cin>>x;
        int run = 0;
        if(x == 'O'){
            out++;balls++;i=k;
        }else if(x == 'W'){
            continue;
        }else{
            b[i] += (x - '0');
            //cout<<i<<" player scored --> "<<b[i]<<endl;
            run = b[i];

            if(run%2){
                int temp = i;
                i = j;
                j = temp;
            }
            balls++;
        }
    }

    for(int i=1;i<4;i++){
        cout<<b[i]<<endl;
    }
}
