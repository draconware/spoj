#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000005
#define CUBE(x) (x*x*x)

LL arr[MAX]={0};
LL cubfr[MAX]={0};

void sieve(){
    LL k;
    for(LL i=2;(CUBE(i))<=MAX;i++){
        if(!(arr[i])){
            k=CUBE(i);
            for(LL j=k;j<MAX;j+=k){
                arr[j]=-1;
            }
        }
    }

}

void free_num(){
    LL k=1;
    for(LL i=1;i<MAX;i++){
        if(!(arr[i])){
            arr[i]=k++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t,n,j=1;
    cin>>t;

    sieve();
    free_num();

    while(t--){
        cin>>n;
        if(arr[n]==-1){
            cout<<"Case "<<j<<": "<<"Not Cube Free"<<endl;
            j++;
            continue;
        }
        cout<<"Case "<<j<<": "<<arr[n]<<endl;
        j++;
    }
    return 0;
}
