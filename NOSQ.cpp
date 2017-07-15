#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 100000

int arr[MAX][11]={0};

void square_free(){
    for(int i=2;(i*i)<=MAX;i++){
        int j=(i*i);

        if(!arr[j][10]){
            for(int k=j;k<=MAX;k+=j){
                arr[k][10]=1;
            }
        }
    }

    for(int i=1;i<=MAX;i++){
        if(!(arr[i][10])){
            int j=i;
            while(j){
                arr[i][j%10]=1;
                j/=10;
            }

            for(int k=0;k<=9;k++){
                arr[i][k]+=arr[i-1][k];
            }
        }else{
            for(int k=0;k<=9;k++){
                arr[i][k]=arr[i-1][k];
            }
        }
    }
}

int main(){
    square_free();

    ios_base::sync_with_stdio(false);

    int t,a,b,d;
    cin>>t;

    while(t--){
        cin>>a>>b>>d;
        int ans;

        ans = arr[b][d] - arr[a-1][d];
        cout<<ans<<endl;
    }
    return 0;
}
