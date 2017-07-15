#include<bits/stdc++.h>
using namespace std;

vector<int> v;
string str;
int flag;

void decrypt(int n,int k,int x,int y){
    vector<int> v1;

    for(int i=0;i<n;i++){
        if( (int)str[i] <= y && (int)str[i] >= x){
            v1.push_back(i);
        }
        if((flag) && (int)str[i]==95){
            v1.push_back(i);
        }
    }

    if(v1.empty()){
        return;
    }else{
        int m = v1.size();
        int v2[m];

        for(int i=0;i<m;i++){
            if(i+k >= m){
                v2[ i+k-((i+k)/m)*m ] = v1[i];
            }else{
                v2[i+k] = v1[i];
            }
        }

        for(int i=0;i<m;i++){
            v[ v1[i] ] = v2[i] ;
        }
    }
}

int main(){
    int k1,k2,k3;

    while(1){
        cin>>k1>>k2>>k3;
        if(!k1 && !k2 && !k3){
            return 0;
        }else{
            cin>>str;

            int n = str.length();
            //cout<<str<<n;

            for(int i=0;i<n;i++){
                v.push_back(0);
            }
            decrypt(n,k1,97,105);
            decrypt(n,k2,106,114);

            flag=1;
            decrypt(n,k3,115,122);
            flag=0;

            for(int i=0;i<n;i++){
                cout<<str[ v[i] ];
            }
            cout<<endl;
        }
        v.clear();
    }
}
