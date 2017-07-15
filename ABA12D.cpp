#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000009

bool mark[MAX];
bool prime[MAX];
vector<LL> v;

LL power(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1){res*=x;}
        y/=2;
        x*=x;
    }
    return res;
}

void pre(){
    for(LL i=0;i<MAX;i++){mark[i]=false;prime[i]=true;}
    prime[0]=false;prime[1]=false;mark[2]=true;
    for(LL i=2;(i*i)<MAX;i++){
        if(prime[i]){
            for(LL j=(i*i);j<MAX;j+=i){
                prime[j]=false;
            }
        }
    }
    for(LL i=2;i<MAX;i++){
        if(prime[i]){
            v.push_back(i);
        }
    }

    for(LL i=0;i<v.size();i++){
        LL x,a = 0;
        //cout<<"observing--- "<<v[i]<<endl;
        while(1){
            a++;
            x = power(v[i],a+1);
            LL y = (x-1)/(v[i]-1);
            //cout<<"a,x,y---- "<<a<<","<<x<<","<<y<<endl;
            if(y >= MAX){
                break;
            }
            if(prime[y]){
                mark[(x/v[i])]=true;
            }
        }
    }
}

int main(){
    pre();
    int t;
    cin>>t;

    while(t--){
        LL n,m,ans=0;
        cin>>n>>m;
        for(int i=n;i<=m;i++){
            if(mark[i]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
