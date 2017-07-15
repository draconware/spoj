#include<bits/stdc++.h>
using namespace std;

#define MAX 10000009

bool mark[MAX];
vector<int> prime;

void pre(){
    memset(mark,1,sizeof(mark));
    for(int i=2;i*i<MAX;i++){
        if(mark[i]){
            for(int j=i*i;j<MAX;j++){
                mark[j]=false;
            }
        }
    }
    for(int i=2;i<MAX;i++){
        if(mark[i]){
            prime.push_back(i);
            //cout<<i<<" ";
        }
    }
}

int main(){
    pre();
    int a,b,x,y;
    cin>>a>>b;

    for(int i=0;i<prime.size() && prime[i]<=a;i++){
        if(a%prime[i] == 0){
            x=prime[i];
            break;
        }
    }
    for(int i=0;i<prime.size() && prime[i]<=b;i++){
        if(b%prime[i] == 0){
            y=prime[i];
            break;
        }
    }
    if(x>=y){
        cout<<"0"<<endl;
    }else if(x<y){
        cout<<(y-x)<<endl;
    }
}
