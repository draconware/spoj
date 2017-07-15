#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    while(1){
        int n,m,ans=0;
        cin>>n;m=n;

        if(n==0){return 0;}
        v.clear();
        for(int i=1;(i*i)<=n;i++){
            if(n%i == 0){
                ans++;
            }
        }
        for(int i=2;(i*i)<=n;i++){
            while(n%i == 0){
                v.push_back(i);
                n/=i;
            }
        }
        if(n>1){
            v.push_back(n);
        }
        cout<<m<<" = "<<v[0];
        for(int i=1;i<v.size();i++){
            cout<<" * "<<v[i];
        }
        cout<<endl;
        cout<<"With "<<m<<" marbles, "<<ans<<" different rectangles can be constructed."<<endl;
    }
}

