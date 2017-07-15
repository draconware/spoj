#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000000

set< pair<int,int> > s;
bool mark[MAX]={true};

void pre(){

    for(int i=2;(i*i)<=MAX;i++){
        if(mark[i]){
            for(int j=(i*i);j<=MAX;j+=i){
                mark[j]=0;
            }
        }
    }

    for(int i=2;i<MAX;i++){
        if(mark[i]){
            s.insert(make_pair(i,0));
        }
    }
}

int main(){
    int n;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=0;i<n;i++){

    }
}
