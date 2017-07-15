#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    LL n,k,sum,count=0;
    cin>>n;

    k=n;

    set<LL> s;
    while(1){
        sum=0;
        while(k>0){
            sum+=((k%10)*(k%10));
            k/=10;
        }
        k=sum;
        if(k==1){
            cout<<(1+s.size())<<endl;
            break;
        }
        if(s.empty()){
            s.insert(k);
            continue;
        }
        if(s.find(k)!=s.end()){
            cout<<"-1"<<endl;
            break;
        }else{
            count++;
            s.insert(k);
        }
    }
    return 0;
}
