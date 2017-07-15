#include<bits/stdc++.h>
using namespace std;

#define MAX 100000009

vector<int> v;
bitset<MAX> prime;
int arr[MAX]={0};

float mode(float x){
    return x>0.0?x:-x;
}

void pre(){
    prime.flip();
    prime[1]=0;
    for(int i=2;(i*i)<MAX;i++){
        if(prime[i]){
            for(int j=(i*i);j<MAX;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<MAX;i++){
        if(prime[i]){
            v.push_back(i);
            arr[i]=arr[i-1]+1;
        }else{
            arr[i]=arr[i-1];
        }
    }
}

int main(){
    pre();

    int n;
    while(1){
        cin>>n;
        if(n==0){return 0;}

        float k=n;
        k/=log(k);

        float ans = abs(arr[n] - k)/(float)arr[n];
        printf("%.1f\n",ans*100);
    }
}
