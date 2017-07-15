#include<bits/stdc++.h>
using namespace std;

#define LL long long

struct cisterns{
    int b,h,w,d,v;
};

bool comp(const cisterns &x,const cisterns &y){
    return (x.b < y.b);
}

bool comp(const cisterns &x,const cisterns &y){
    return (x.h < y.h);
}
int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    vector<struct cisterns> v,m;

    while(t--){
        struct cisterns temp;
        vector<struct cisterns>::iterator it;
        int n,given_volume;
        cin>>n;

        for(int i=0;i<n;i++){
            cin>> temp.b >> temp.h >> temp.w >> temp.d ;
            temp.v=(temp.h)*(temp.w)*(temp.d);
            v.push_back(temp);
        }
        m=v;

        sort(v.begin(),v.end(),comp);
        sort(m.begin(),m.end(),comp2);

        LL volume=0;
        for(it=v.begin();it!=v.end();it++){
            volume += *it.v;
        }
        cin>>given_volume;
        if(volume < given_volume){
            cout<<"OVERFLOW"<<endl;
        }else if(volume==given_volume){
            cout<< max( (v[n-1].b + v[n-1].h ),( m[n-1].b + m[n-1].h ))<<endl;
        }else{

        }
    }
    return 0;
}
