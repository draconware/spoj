#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;
    while(t--){
        LL a,b;
        cin>>a>>b;

        LL currentsum=0,maxsum=1000000000;
        LL left=0,right=0,maxsize=0,length=0;
        LL station[a];

        for(LL i=0;i<a;i++){
            cin>>station[i];
        }
        while(right < a){
            currentsum+=station[right];
            length++;

            if(currentsum > b){
                while(currentsum > b){
                    currentsum-=station[left];
                    left++;
                    length--;
                }
            }
            if(length > maxsize){
                maxsize=length;
                maxsum = currentsum;
            }else if(length == maxsize){
                if(currentsum < maxsum)
                    maxsum=currentsum;
            }
            right++;
        }
        cout<<maxsum<<" "<<maxsize<<endl;
    }
    return 0;
}
