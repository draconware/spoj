#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    vector<LL> v;
    vector<LL>::iterator it;
    v.push_back(1);
    v.push_back(3);

    it=lower_bound(v.begin(),v.end(),2);
    cout<<(it-v.begin())<<endl;
}
