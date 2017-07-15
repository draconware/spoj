#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        LL xp,nb,count=0;
        cin>>xp>>nb;

        while(1){
            if((xp==0)||(nb==0)){
                break;
            }
            if((xp==1)||(nb==1)){
                if(nb>1){
                    count++;
                }
                if(xp>1){
                    count++;
                }
                break;
            }
            if(xp>nb){
                xp-=2;
                nb--;
                count++;
            }else{
                xp--;
                nb-=2;
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
