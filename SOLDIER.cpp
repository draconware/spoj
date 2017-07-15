#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,a,b,c;
    cin>>n>>t;

    int quality[7];
    for(int i=1;i<=6;i++){quality[i]=-1;}

    while(n--){
        cin>>a>>b>>c;
        if(quality[a] < c){quality[a]=c;}
    }
    int mini=INT_MAX;
    for(int i=1;i<=6;i++){
        if(quality[i] < mini){
            mini = quality[i];
        }
    }
    if(mini == -1){cout<<"0"<<endl;}
    else{cout<<mini<<endl;}
}
