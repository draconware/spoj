#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    LL n,sum;
    cin>>n;

    set<LL> s;
    set<LL>::iterator it;
    while(1){
        sum=0;
        while(n>0){
            sum+=((n%10)*(n%10));
            n/=10;
        }
        n=sum;
        if(sum==1){
            cout<<1+s.size()<<endl;
        }
        if(!s.empty()){
            it=s.find(sum);
            if(it){
                s.insert(sum);
            }else{
                cout<<"-1"<<endl;
                break;
            }
        }else{
            s.insert(sum);
        }
    }
    return 0;
}
