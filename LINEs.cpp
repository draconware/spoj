#include<bits/stdc++.h>
using namespace std;

set< pair<int,int> > s;
vector< pair<int,int> > v;

int mod(int i){
    return i>=0?i:-i;
}

int gcd(int a,int b){
    if(a == 0){
        return b;
    }
    gcd(b%a,a);
}

int main(){
    while(1){
        int n;
        cin>>n;
        if(n==0){return 0;}
        s.clear();v.clear();
        int x,y;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dx = (v[i].first - v[j].first);
                int dy = (v[i].second - v[j].second);

                int d = gcd(mod(dx),mod(dy));
                s.insert(make_pair(dx/d , dy/d));
            }
        }
        cout<<s.size()<<endl;
    }
    return 0;
}
