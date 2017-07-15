#include<bits/stdc++.h>
using namespace std;

int c,i;
string str;

void depth(){
    if(str[i] == 'l'){
        return;
    }else{
        c++;
        i++;
        depth();
        i++;
        depth();
    }
}
int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>str;

        c=0;i=0;
        depth();
        cout<<c<<endl;
    }
}
