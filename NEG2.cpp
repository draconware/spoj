#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==0){cout<<"0"<<endl;return 0;}
    vector<int> v;
    while(n != 0){
        //cout<<n<<endl;
        v.push_back(abs(n)%2);
        if(abs(n)%2 == 0){
            n = n/(-2);
        }else{
            if(n<0){n = abs(n)/2 +1;}
            else{n = abs(n)/2;n = -n;}
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
    }
    cout<<endl;
}
