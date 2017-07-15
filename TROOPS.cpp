#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int c;
    int t;
    int s;
}monster;

bool comp(const monster& m1,const monster& m2){
    return m1.t < m2.t;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        monster arr[n];

        for(int i=0;i<n;i++){
            cin>> arr[i].c >> arr[i].t >> arr[i].s ;
        }

        sort(arr,arr+n,comp);

    }
    return 0;
}
