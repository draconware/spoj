#include<iostream>
#define LL long long
#define SET 1000000007
using namespace std;

LL power(LL i,LL j){
    LL result=1;

    while(j>0){
        if(j & 1){
            result=(result*i)%SET;
        }
        j=j>>1;
        i=(i*i)%SET;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;
    while(t--){
        LL m,n,x,y,temp;
        cin>>m>>n;
        temp=power(m,n);
        y=temp;
        x=(((temp-1+SET)%SET)*(power(m-1,SET-2)))%SET;
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}

