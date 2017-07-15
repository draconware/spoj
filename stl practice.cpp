#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()

int main(){
    vector<int> v;

    int p,ans;
    for(int i=0;i<6;i++){
        cin>>p;
        v.push_back(p);
    }

    cout<< accumulate(all(v),0) << endl;
}
