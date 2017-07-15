#include<bits/stdc++.h>
using namespace std;

#define LL long long
vector<pair<double,double> > v;
set<pair<double,double> > s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n,a,b,i=0;
        cin>>n>>a>>b;
        v.clear();

        double x1=0,y1=1,x2=1,y2=n,x=0,y=0;
        v.push_back(make_pair(x1,y1));
        v.push_back(make_pair(x2,y2));

        while(y != 1.0){
            x = floor((y1+n)/y2)*x2 - x1;
            y = floor((y1+n)/y2)*y2 - y1;
            v.push_back(make_pair(x,y));
            x1=x2;x2=x;y1=y2;y2=y;
            if(x == a && y == b){
                cout<<i+3<<endl;
                break;
            }
            i++;
        }
    }
}
