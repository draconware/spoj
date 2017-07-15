#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000009

bool mark[MAX];
vector<int> v[MAX];

void pre(){
    memset(mark,1,sizeof(mark));
    for(int i=2;i<MAX;i++){
        if(mark[i]){
            v[i].push_back(i);
            for(int j=(i*2);j<MAX;j+=i){
                mark[j]=false;
                v[j].push_back(i);
            }
        }
    }
}

int main(){
    pre();
    int t,n,c=0;
    cin>>t;

    while(t--){
        c++;
        cin>>n;
        cout<<"Case "<<c<<": ";
        for(int i=0;i<v[n].size();i++){
            cout<<v[n][i]<<" ";
        }
        cout<<endl;
    }
}
