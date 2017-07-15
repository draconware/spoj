#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int g,b;
    while(1){
        cin>>g>>b;
        if((g==-1)&&(b==-1)){
            return 0;
        }
        if(!g){
            if(!b){
                cout<<b<<endl;
            }else{
                cout<<b<<endl;
            }
            continue;
        }
        if(!b){
            if(!g){
                cout<<g<<endl;
            }else{
                cout<<g<<endl;
            }
            continue;
        }
        if(g==b){
            cout<<"1"<<endl;
            continue;
        }
        int c = g > b ? g : b;
        int d = g < b ? g : b;

        int ans = ceil((float)c/((float)d+1.0));
        cout<<ans<<endl;
    }
}
