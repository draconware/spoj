#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;
    while(t--){
        LL p,m;
        cin>>p>>m;

        LL currentbots=0,maxbots=1000000;
        LL length=0,maxsize=0;
        LL right=0,left=0;
        LL planet[p];

        for(LL i=0;i<p;i++){
            cin>>planet[i];
        }
        while(right<p){
            currentbots+=planet[right];
            length++;

            #include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;
    while(t--){
        LL p,m;
        cin>>p>>m;

        LL currentbots=0,maxbots=1000000;
        LL length=0,maxsize=0;
        LL right=0,left=0;
        LL planet[p];

        for(LL i=0;i<p;i++){
            cin>>planet[i];
        }
        while(right<p){
            currentbots+=planet[right];
            length++;

            if(currentbots > m){
                while(currentbots > m){
                    currentbots-=planet[left];
                    left++;
                    length--;
            }
        }

            if(length > maxsize){
                maxsize=length;
                maxbots=currentbots;
            }else if(length == maxsize){
                if(currentbots < maxbots)
                    maxbots=currentbots;
            }
            right++;
        }
        cout<<maxbots<<" "<<maxsize<<endl;
    }
    return 0;
}

            right++;
        }
        cout<<maxbots<<" "<<maxsize<<endl;
    }
    return 0;
}
