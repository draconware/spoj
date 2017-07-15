#include<bits/stdc++.h>
using namespace std;

#define MAX 1000009

int arr[MAX];
bool mark[1009];
vector<int> prime;
bool visit[MAX];

void pre(){
    memset(mark,1,sizeof(mark));
    for(int i=2;i*i<1009;i++){
        if(mark[i]){
            for(int j={i*i};j<1009;j+=i){
                mark[j]=false;
            }
        }
    }
    for(int i=2;i<1009;i++){
        if(mark[i]){
            prime.push_back(i);
            //cout<<i<<" ";
        }
    }
}

int main(){
    pre();

    int a,b,c=0;
    while(1){
        c++;
        cin>>a>>b;
        if(a==0 && b==0){return 0;}

        memset(arr,0,sizeof(arr));
        memset(visit,0,sizeof(visit));
        for(int i=0;i<prime.size() && (prime[i]*prime[i])<=a;i++){
            int e=0;
            while(a%prime[i] == 0){
                visit[prime[i]]=true;
                e++;
                a/=prime[i];
            }
            arr[prime[i]]=abs(arr[prime[i]] - e);
        }
        if(a>1){arr[a]=abs(arr[a] - 1);visit[a]=true;}

        for(int i=0;i<prime.size() && (prime[i]*prime[i])<=b;i++){
            int e=0;
            while(b%prime[i] == 0){
                visit[prime[i]]=true;
                e++;
                b/=prime[i];
            }
            arr[prime[i]]=abs(arr[prime[i]] - e);
        }
        if(b>1){arr[b]=abs(arr[b] - 1);visit[b]=true;}
        long ans=0,ordinal=0;
        for(int i=0;i<MAX;i++){
            ans+=arr[i];
            if(visit[i]){
                ordinal++;
            }
        }
        cout<<c<<". "<<ordinal<<":"<<ans<<endl;
    }
    return 0;
}
